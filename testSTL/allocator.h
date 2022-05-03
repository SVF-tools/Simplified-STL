//allocator  1
class malloc_alloc
{
public:

    static void* allocate(size_t n)
    {
        void* result=malloc(n);
        if(0==result) result=oom_malloc(n);
        return result;
    }
    //to be perfected
    static void deallocate(void* p)
    {
        free(p);
    }
    static void* reallocate(void *p,size_t new_sz)
    {
        void* result=realloc(p,new_sz);
        if(0==result) result=oom_realloc(p,new_sz);
        return result;
    }
    static void (*set_malloc_handler(void (*f)()))()
    {
        void (*old)()=__malloc_alloc_oom_handler;
        __malloc_alloc_oom_handler=f;
        return old;
    }

private:
    static void* oom_malloc(size_t n)
    {
        void (*my_malloc_handler)();
        void* result;

        for(;;){
            my_malloc_handler=__malloc_alloc_oom_handler;
            //assert(0!=my_malloc_handler);
            (*my_malloc_handler)();
            result=malloc(n);
            if(result) return result;
        }
    }
    static void* oom_realloc(void* p,size_t n)
    {
        void (*my_malloc_handler)();
        void* result;

        while(true){
            my_malloc_handler=__malloc_alloc_oom_handler;
            //assert(0!=my_malloc_handler);
            (*my_malloc_handler)();
            result=realloc(p,n);
            if(result) return result;
        }
    }
    static void (*__malloc_alloc_oom_handler)();
};



template <class T>
void construct(T* p)
{
    new (p) T();
}

template <class T1,class T2>
void construct(T1* p,const T2& value)
{
    new (p) T1(value);
}

template <class T,typename... Args>
void construct(T* p,const Args& ... args)
{
    new (p) T(args...);
}

template <class T1,class T2>
void construct(T1* p,T2&& value)
{
    new (p) T1(std::move(value));
}

//to be optimized

template <class T>
void destroy(T* pointer)
{
    pointer->~T();
}

//destroy range
template <class InputIterator>
void destroy(InputIterator begin,InputIterator end)
{
    while(begin!=end)
        destroy(&*begin++);
}
template <class InputIterator,typename Size>
void destroy(InputIterator begin,Size n)
{
    while(n--)
        destroy(&*begin++);
}

template <class InputIterator,class ForwardIterator>
ForwardIterator uninitialized_copy(InputIterator begin,
                                   InputIterator end,
                                   ForwardIterator result)
{
    while(begin!=end)
        construct(&*result++,*begin++);
    return result;
}

template <class InputIterator,class ForwardIterator,typename Size>
ForwardIterator uninitialized_copy_n(InputIterator begin,
                                     Size n,
                                     ForwardIterator result)
{
    while(n--)
        construct(&*result++,*begin++);
    return result;
}

template <class InputIterator,class ForwardIterator>
ForwardIterator uninitialized_shear(InputIterator begin,
                                    InputIterator end,
                                    ForwardIterator result)
{
    while(begin!=end)
        construct(&*result++,std::move(*begin++));
    return result;
}

template <class InputIterator,class ForwardIterator,typename Size>
ForwardIterator uninitialized_shear_n(InputIterator begin,
                                      Size n,
                                      ForwardIterator result)
{
    while(n--)
        construct(&*result++,std::move(*begin++));
    return result;
}

template <class ForwardIterator>
void uninitialized_fill(ForwardIterator begin,ForwardIterator end)
{
    while(begin!=end)
        construct(&*begin++);
}

template <class ForwardIterator,class T>
void uninitialized_fill(ForwardIterator begin,
                        ForwardIterator end,
                        const T& t)
{
    while(begin!=end)
        construct(&*begin++,t);
}

template <class ForwardIterator,typename Size>
ForwardIterator uninitialized_fill_n(ForwardIterator begin,
                                     Size n)
{
    while(n--)
        construct(&*begin++);
    return begin;
}

template <class ForwardIterator,typename Size,class T>
ForwardIterator uninitialized_fill_n(ForwardIterator begin,
                                     Size n,
                                     const T& t)
{
    while(n--)
        construct(&*begin++,t);
    return begin;
}

template <class T,class Alloc>
struct simple_alloc
{
    static T* allocate(size_t n)
    {
        return 0==n?0:(T*)Alloc::allocate(n*sizeof(T));
    }
    static T* allocate()
    {
        return (T*)Alloc::allocate(sizeof(T));
    }
    //to be perfected
    static void deallocate(T* p)
    {
        return Alloc::deallocate(p);
    }
};

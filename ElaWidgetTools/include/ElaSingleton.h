#ifndef ELASINGLETON_H
#define ELASINGLETON_H

#include <QMutex>

template <typename T>
class ElaSingleton
{
public:
    static T* getInstance();

private:
    Q_DISABLE_COPY(ElaSingleton)
};

template <typename T>
T* ElaSingleton<T>::getInstance()
{
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    static T* instance = nullptr;
    if (instance == nullptr)
    {
        instance = new T();
    }
    return instance;
}

#define Q_SINGLETON_CREATE(Class)               \
private:                                        \
    friend class ElaSingleton<Class>;              \
                                                \
public:                                         \
    static Class* getInstance()                 \
    {                                           \
        return ElaSingleton<Class>::getInstance(); \
    }

#define Q_SINGLETON_CREATE_H(Class) \
private:                            \
    static Class* _instance;        \
                                    \
public:                             \
    static Class* getInstance();

#define Q_SINGLETON_CREATE_CPP(Class)  \
    Class* Class::_instance = nullptr; \
    Class* Class::getInstance()        \
    {                                  \
        static QMutex mutex;           \
        QMutexLocker locker(&mutex);   \
        if (_instance == nullptr)      \
        {                              \
            _instance = new Class();   \
        }                              \
        return _instance;              \
    }

#endif // ELASINGLETON_H

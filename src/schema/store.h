#ifndef _STORE_H_
#define _STORE_H_

#include <string>
#include <vector>

class Store {
  public:
    virtual void add(std::string[]) = 0;
};

template<class T> class StoreBase : public Store {
  protected:
    std::vector<T> store;
    virtual void onNewItem(T*, uint64_t) = 0;

  public:
    void add_instance(T);
    virtual void add(std::string[]) = 0;
    unsigned long count();
};

template<class T> void StoreBase<T>::add_instance(T item) {
  store.push_back(item);
  onNewItem(&store.back(), store.size() - 1);
}

template<class T> unsigned long StoreBase<T>::count() {
  return store.size();
}

#endif

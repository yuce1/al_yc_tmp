// way1:hashmap+双向队列
class LRUCache {

private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : cap(capacity) {
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        auto key_value = *map[key];
        cache.erase(map[key]);
        cache.push_front(key_value);
        map[key] = cache.begin();
        return key_value.second;
    }

    void put(int key, int value) {
        if (map.find(key) == map.end()) {
            if (cache.size() == cap) {
                map.erase(cache.back().first);
                cache.pop_back();
            }
        }
        else {
            cache.erase(map[key]);
        }
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};



// way2：手撕双向队列

// 总的思想就是 哈希双向链表
struct Node
{
    int key;
    int value;
    Node* pre;
    Node* next;
    Node(int key, int value) : key(key), value(value), pre(nullptr), next(nullptr){}
};
class LRUCache {
private:
    int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> p;

public:
    LRUCache(int capacity) {
        this->size = capacity;
        head = nullptr;
        tail = nullptr;
    }
    // 获取缓冲区中 key 对应的 value
    int get(int key) {
        // 1.当该 key 值存在
        if(p.count(key) > 0)
        {
            // 删除该 key 对应的原来节点
            Node* cur = p[key];
            int value = cur->value;
            remove(cur);   // 这里仅仅删除哈希双向链表中的节点，不必删除哈希表中的                 
            // 将节点重现插入到缓冲区的头部
            setHead(cur);                     
            return value;
        }
        // 2.当该 key 值不存在
        return -1;
    }

    // 将key-value值存入缓冲区
    void put(int key, int value) {
        // 1.当该 key 值存在
        if(p.count(key) > 0)
        {
            // 删除该 key 对应的原来节点
            Node* cur = p[key];
            cur->value = value;
            remove(cur);    // 这里仅仅删除哈希双向链表中的节点，不必删除哈希表中的                                
            // 将节点重现插入到缓冲区的头部
            setHead(cur);
        }
        else// 2.当该 key 值不存在
        {
            Node* node = new Node(key, value);
            // 判断当前缓冲区大小已经满了
            if(p.size() >= size)
            {
                // 删除尾部节点
                // auto it = p.find(tail->key);// 返回迭代器类型
                p.erase(tail->key);
                remove(tail);
                // 这里erase 函数参数是迭代器类型，所以上面需要使用迭代器类型
                // 将新节点插入到缓冲区的头部
            }
            //else 此时因为动作和上面重复，所以直接合并使用
            //还没有满：将新节点插入到缓冲区的头部
            {
                setHead(node);
                p[key] = node;
            }
        }
    }

    // 删除当前节点
    void remove(Node* cur)
    {
        if(head == tail) {
            head = tail = nullptr;
            return ;
        }
        // 当前节点是 head
        if(cur == head)
            head = cur->next;
        else if(cur == tail)// 当前节点是 tail
            tail = cur->pre;
        else// 当前节点是一般节点
        {
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
        }
    }
    
    // 将当前节点插入到头部
    void setHead(Node* cur)
    {
        cur->next = head;
        if(head != nullptr)
            head->pre = cur;
        head = cur;//重现更新head

        if(tail==nullptr)
            tail = head;
    }
};

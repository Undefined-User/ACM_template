template <typename KEY_type, typename Value_type, size_t LEN, int des(KEY_type, int)>
struct Hash {
    static const int mod = 38281;
    int head[mod];
    KEY_type key[LEN];
    Value_type value[LEN];
    int Nxt[LEN], ntot;

    void init() {
        ntot = 0;
        memset(head, 0, sizeof(head));
    }

    void insert(int v, int r) {
        int k = des(v, mod);
        ntot++;
        Nxt[ntot] = head[k];
        key[ntot] = v;
        value[ntot] = r;
        head[k] = ntot;
    }

    int query(int v) {
        int k = des(v, mod);
        for (int t = head[k]; t; t = Nxt[t]) {
            if (key[t] == v) {
                return value[t];
            }
        }
        return -1;
    }
};
auto fun(int v, int m)->int {
    return (v % m + m) % m;
}
Hash<int,int,38281*8,fun> hasher;

template <typename T, size_t LEN, int des(T, int)>
struct Hash {
    static const int mod = 38281;
    int head[mod];
    T key[LEN];
    int Nxt[LEN], ntot;

    void init() {
        ntot = 0;
        memset(head, 0, sizeof(head));
    }

    void insert(int v, int r) {
        int k = des(v, mod);
        ntot++;
        Nxt[ntot] = head[k];
        key[ntot] = v;
        head[k] = ntot;
    }

    bool contains(int v) {
        int k = des(v, mod);
        for (int t = head[k]; t; t = Nxt[t]) {
            if (key[t] == v) {
                return true;
            }
        }
        return false;
    }
    
    int size() const{
        return ntot;
    }
    
};
auto fun(int v, int m)->int {
    return (v % m + m) % m;
}
Hash<int,38281*8,fun> hasher;

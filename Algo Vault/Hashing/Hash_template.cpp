class HashedString
{
private:
    // change M and B if you want
    static const long long M = 1e9 + 9;
    static const long long B = 9973;

    // pow[i] contains B^i % M
    static vector<long long> pow;

    // p_hash[i] is the hash of the first i characters of the given string
    vector<long long> p_hash;
    vector<long long> p_hash_rev;

public:
    HashedString(string &s) : p_hash(s.size() + 1), p_hash_rev(s.size() + 1)
    {
        while (pow.size() < s.size())
        {
            pow.push_back((pow.back() * B) % M);
        }

        p_hash[0] = p_hash_rev[0] = 0;
        for (int i = 0; i < s.size(); i++)
        {
            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
        for (int i = s.size() - 1; i >= 0; i--)
        {
            p_hash_rev[i] = ((p_hash_rev[i + 1] * B) % M + s[i]) % M;
        }
    }

    long long getHash(int start, int end)
    {
        long long raw_val =
            (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
        return (raw_val % M + M) % M;
    }
    long long getHashRev(int start, int end)
    {
        long long raw_val =
            (p_hash_rev[start] - (p_hash_rev[end + 1] * pow[end - start + 1]));
        return (raw_val % M + M) % M;
    }
    long long getPow(int p)
    {
        return pow[p];
    }
};
vector<long long> HashedString::pow = {1};
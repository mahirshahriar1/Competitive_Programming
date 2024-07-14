#include <bits/stdc++.h>
using namespace std;

constexpr int PR[] = {2147462393, 2147462419, 2147462587, 2147462633, 2147462747, 2147463167, 2147463203, 2147463569, 2147463727, 2147463863, 2147464211, 2147464549, 2147464751, 2147465153, 2147465563, 2147465599, 2147465743, 2147465953, 2147466457, 2147466463, 2147466521, 2147466721, 2147467009, 2147467057, 2147467067, 2147467261, 2147467379, 2147467463, 2147467669, 2147467747, 2147468003, 2147468317, 2147468591, 2147468651, 2147468779, 2147468801, 2147469017, 2147469041, 2147469173, 2147469229, 2147469593, 2147469881, 2147469983, 2147470027, 2147470081, 2147470177, 2147470673, 2147470823, 2147471057, 2147471327, 2147471581, 2147472137, 2147472161, 2147472689, 2147472697, 2147472863, 2147473151, 2147473369, 2147473733, 2147473891, 2147473963, 2147474279, 2147474921, 2147474929, 2147475107, 2147475221, 2147475347, 2147475397, 2147475971, 2147476739, 2147476769, 2147476789, 2147476927, 2147477063, 2147477107, 2147477249, 2147477807, 2147477933, 2147478017, 2147478521};
array<int, 2> base{47, 59}, mod{int(1E9 + 7), int(1E9 + 9)};
 
void init() {
  constexpr int nprimes = (sizeof(PR) / sizeof(PR[0])) / 4;
 
  auto rand = [&]() -> int {
    uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 mt(seed);
    uniform_int_distribution<int> num(0, nprimes - 1);
    return num(mt);
  };
 
  base[0] = PR[rand()];
  mod[0] = PR[rand() + nprimes];
  base[1] = PR[rand() + 2 * nprimes];
  mod[1] = PR[rand() + 3 * nprimes];
}
struct polynomial_hash {
  std::array<int, 2> base = ::base;
  std::array<int, 2> mod = ::mod;
  std::array<std::vector<int>, 2> f_hash, r_hash;
  std::array<std::vector<int>, 2> expo;
  std::string s;
  int size = 0;
  using s_it = std::string::iterator;
 
  polynomial_hash() = default;
 
  polynomial_hash(s_it st, s_it ed) {
    polynomial_hash::init(st, ed);
  }
  explicit polynomial_hash(std::string s) {
    polynomial_hash::init(s.begin(), s.end());
  }
  polynomial_hash(s_it st, s_it ed, std::initializer_list<int> base, std::initializer_list<int> mod) {
    for (const int& i : {0, 1}) {
      polynomial_hash::base[i] = *(base.begin() + i);
      polynomial_hash::mod[i] = *(mod.begin() + i);
    }
    polynomial_hash::init(st, ed);
  }
 
  void set_string(std::string s) {
    polynomial_hash::init(s.begin(), s.end());
  }
 
  void init(s_it st, s_it ed) {
    polynomial_hash::s = std::string(st, ed);
    polynomial_hash::size = (int) distance(st, ed);
  }
 
  void resize(int i = 0) {
    polynomial_hash::f_hash[i].resize(size, 0);
    polynomial_hash::r_hash[i].resize(size, 0);
    polynomial_hash::expo[i].resize(size + 1, 1);
  }
 
  void compute_expo(int i = 0) {
    for (int j = 1; j <= polynomial_hash::size; ++j) {
      expo[i][j] = int((1LL * expo[i][j - 1] * base[i]) % mod[i]);
    }
  }
  void compute_single_hash(int i = 0) {
    resize(i);
    compute_expo(i);
    int fh = 0, rh = 0;
    for (int j = 0; j < polynomial_hash::size; ++j) {
      fh = int((1LL * fh * base[i] + s[j]) % mod[i]);
      rh = int((1LL * rh * base[i] + s[polynomial_hash::size - j - 1]) % mod[i]);
      polynomial_hash::f_hash[i][j] = fh;
      polynomial_hash::r_hash[i][polynomial_hash::size - 1 - j] = rh;
    }
  }
 
  void compute_double_hash() {
    compute_single_hash(0);
    compute_single_hash(1);
  }
 
  uint64_t get_single_f_hash(int l, int r, int i = 0) {
    if (l > r) return 0;
    int h = 0;
    h = int((f_hash[i][r] - (l > 0 ? 1LL * f_hash[i][l - 1] * expo[i][r - l + 1] : 0)) % mod[i]);
    return h < 0 ? h += mod[i] : h;
  }
 
  uint64_t get_double_f_hash(int l, int r) {
    return (polynomial_hash::get_single_f_hash(l, r, 0) << 32) ^ polynomial_hash::get_single_f_hash(l, r, 1);
  }
 
  uint64_t get_single_r_hash(int l, int r, int i = 0) {
    int h = 0;
    h = int((r_hash[i][l] - (r < size - 1 ? 1LL * r_hash[i][r + 1] * expo[i][r - l + 1] : 0)) % mod[i]);
    return h < 0 ? h += mod[i] : h;
  }
 
  uint64_t get_double_r_hash(int l, int r) {
    return (polynomial_hash::get_single_r_hash(l, r, 0) << 32) ^ polynomial_hash::get_single_r_hash(l, r, 1);
  }
 
  int length() const {
    return polynomial_hash::size;
  }
};

void run_case([[maybe_unused]] const int &tc) {
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;

    init();
    polynomial_hash hash(s);
    hash.compute_double_hash();

    auto check = [&] (int mid) {
        int cnt = 0;
        auto hsh = hash.get_double_f_hash(0, mid - 1); 
        for (int i = 0; i + mid - 1 < n;) {
            if (hsh == hash.get_double_f_hash(i, i + mid - 1)) {
                i += mid;
                ++cnt;
            } else {
                ++i;
            }
        }
        return cnt >= l;
    };

    int lo = 1, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {    
        run_case(tc);        
    }

    return 0;
}
/*
2020 Made by Bach Ta
*/


#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define SUM(v) accumulate(all(v), 0)
#define last(v) (v)[(v).size()-1]
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define per(i, a, n) for(int i = a; i >= n; i--)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "YES"
#define N "NO"
using namespace std;

ll fac(ll n) {
	return (n <= 1 ? 1 : n * fac(n-1));
}

ll gcd(ll a, ll b) {
	if (a == 0) return b;
	if (a < b) swap(a, b);
	return gcd(a%b, b);
}

ll bino(ll n, ll r) {
	if (r > n) return 0;
	ll p = 1, k = 1; 
    r = min(r, n-r);
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            ll m = __gcd(p, k); 
            p /= m; 
            k /= m;
            n--; 
            r--; 
        } 
    } 
    else
        p = 1;   
    return p;
}

ll cntdiv(ll n) {
	ll cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) {
            if (n / i == i) 
                cnt++; 
            else
                cnt += 2;
        } 
    } 
    return cnt;
}

vi prime(int n) {
	vi v;
	vector<bool> check(n+1, 0);
	for (int i = 2; i <= n; i++) {
		if (!check[i]) {
			for (int j = 2*i; j <= n; j += i) {
				check[j] = 1;
			}
		}
	}
	
	for (int i = 2; i <= n; i++) {
		if (!check[i]) v.pb(i);
	}
	return v;
}

void eea(ll m, ll n) {
	ll x, y, gcd = 0, row;
	vector<ll> tab_en[4];
	tab_en[0].pb(1);
	tab_en[1].pb(0);
	tab_en[2].pb(m);
	tab_en[3].pb(0);
	tab_en[0].pb(0);
	tab_en[1].pb(1);
	tab_en[2].pb(n);
	tab_en[3].pb(0);
	int i = 2;
	while (!gcd) {
		tab_en[3].pb(tab_en[2][i-2] / tab_en[2][i-1]);
		tab_en[2].pb(tab_en[2][i-2] % tab_en[2][i-1]);
		tab_en[0].pb(tab_en[0][i-2] - tab_en[0][i-1] * tab_en[3][i]);
		tab_en[1].pb(tab_en[1][i-2] - tab_en[1][i-1] * tab_en[3][i]);
		if (!tab_en[2][i]) {
			row = i;
			x = tab_en[0][i-1];
			y = tab_en[1][i-1];
			gcd = tab_en[2][i-1];
		}
		i++;
	}
	cout << '\n';
	cout << "x y r q\n";
	for (int i = 0; i <= row; i++) {
		for (int j = 0; j < 4; j++) {
			cout << tab_en[j][i] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << "A solution to " << m << "x + " << n << "y = d, where d = gcd(" << m << ", " << n << ") is:\n\n";
	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';
	cout << "d = gcd(" << m << ", " << n << ") = " << gcd << '\n';
	cout << "(in row " << row << " of the EEA table)\n\n";
	cout << "Print LaTeX table? 1/0 ";
	int ans;
	cin >> ans;
	if (ans) {
		string newline = "\\\\ ";
		string hline = "\\hline";
		cout << "\n\\begin{center}\\begin{tabular}{|c|c|c|c|}\n";
		cout << hline << "$x$ & $y$ & $r$ & $q$ " << newline << hline << '\n';
		for (int i = 0; i <= row; i++) {
			for (int j = 0; j < 3; j++)
				cout << '$' << tab_en[j][i] << "$ & ";
			cout << '$' << tab_en[3][i] << "$ " << newline << hline << '\n';
		}
		cout << "\\end{tabular}\\end{center}\n\n";
	}	
}

void lde(ll m, ll n, ll q) {
	ll x, y, gcd = 0, row;
	vector<ll> tab_en[4];
	tab_en[0].pb(1);
	tab_en[1].pb(0);
	tab_en[2].pb(m);
	tab_en[3].pb(0);
	tab_en[0].pb(0);
	tab_en[1].pb(1);
	tab_en[2].pb(n);
	tab_en[3].pb(0);
	int i = 2;
	while (!gcd) {
		tab_en[3].pb(tab_en[2][i-2] / tab_en[2][i-1]);
		tab_en[2].pb(tab_en[2][i-2] % tab_en[2][i-1]);
		tab_en[0].pb(tab_en[0][i-2] - tab_en[0][i-1] * tab_en[3][i]);
		tab_en[1].pb(tab_en[1][i-2] - tab_en[1][i-1] * tab_en[3][i]);
		if (!tab_en[2][i]) {
			row = i;
			x = tab_en[0][i-1];
			y = tab_en[1][i-1];
			gcd = tab_en[2][i-1];
		}
		i++;
	}
	cout << '\n';
	if (q != q / gcd * gcd) cout << "No solution\n\n";
	else {
		ll step1, step2;
		x *= (q / gcd);
		y *= (q / gcd);
		step1 = n / gcd;
		step2 = m / gcd;
		string sign1, sign2;
		if (step1 < 0) sign1 = " - ";
		else sign1 = " + ";
		if (step2 < 0) sign2 = " + ";
		else sign2 = " - ";
		step1 = abs(step1), step2 = abs(step2);
		cout << "The set of all solutions to " << m << "x + " << n << "y = " << q << " is {(x, y)}, where:\n\n";
		cout << "x = " << x << sign1 << step1 << 'n' << '\n';
		cout << "y = " << y << sign2 << step2 << 'n' << '\n';
		cout << "(n is an integer)\n\n";
	}
}

void lico(ll coef, ll c, ll mod) {
	ll m = coef, n = mod, q = c;
	ll x, y, gcd = 0, row;
	vector<ll> tab_en[4];
	tab_en[0].pb(1);
	tab_en[1].pb(0);
	tab_en[2].pb(m);
	tab_en[3].pb(0);
	tab_en[0].pb(0);
	tab_en[1].pb(1);
	tab_en[2].pb(n);
	tab_en[3].pb(0);
	int i = 2;
	while (!gcd) {
		tab_en[3].pb(tab_en[2][i-2] / tab_en[2][i-1]);
		tab_en[2].pb(tab_en[2][i-2] % tab_en[2][i-1]);
		tab_en[0].pb(tab_en[0][i-2] - tab_en[0][i-1] * tab_en[3][i]);
		tab_en[1].pb(tab_en[1][i-2] - tab_en[1][i-1] * tab_en[3][i]);
		if (!tab_en[2][i]) {
			row = i;
			x = tab_en[0][i-1];
			y = tab_en[1][i-1];
			gcd = tab_en[2][i-1];
		}
		i++;
	}
	cout << '\n';
	if (q != q / gcd * gcd) cout << "No solution\n\n";
	else {
		int step = mod/gcd;
		x *= (q / gcd);
		y *= (q / gcd);
		if (x < mod) {
			while (x < 0) x += step;
		} else {
			while (x >= step) x -= step;
		}
		cout << "The set of all solutions to " << coef << "x == " << c << " (mod " << mod << ") is x == ";
		cout << x;
		ll y = x;
		vector<ll> list;
		while (x + step < mod) {
			x += step;
			list.pb(x);
		}
		// for (auto item : list) cout << ", " << item; // PC
		for (int i = 0; i < list.size(); i++) cout << ", " << list[i];
		cout << " (mod " << mod << ")\n";
		
		if (!list.empty()) cout << "or equivalently, " << "x == " << y << " (mod " << step << ")\n\n";
	}
}

void simlico(ll c1, ll m1, ll c2, ll m2) {
	ll m = m2, n = m1, q = c1 - c2;
	ll x, y, gcd = 0, row;
	vector<ll> tab_en[4];
	tab_en[0].pb(1);
	tab_en[1].pb(0);
	tab_en[2].pb(m);
	tab_en[3].pb(0);
	tab_en[0].pb(0);
	tab_en[1].pb(1);
	tab_en[2].pb(n);
	tab_en[3].pb(0);
	int i = 2;
	while (!gcd) {
		tab_en[3].pb(tab_en[2][i-2] / tab_en[2][i-1]);
		tab_en[2].pb(tab_en[2][i-2] % tab_en[2][i-1]);
		tab_en[0].pb(tab_en[0][i-2] - tab_en[0][i-1] * tab_en[3][i]);
		tab_en[1].pb(tab_en[1][i-2] - tab_en[1][i-1] * tab_en[3][i]);
		if (!tab_en[2][i]) {
			row = i;
			x = tab_en[0][i-1];
			y = tab_en[1][i-1];
			gcd = tab_en[2][i-1];
		}
		i++;
	}
	cout << '\n';
	if (q != q / gcd * gcd) cout << "No solution\n\n";
	else {
		ll mod = m1 * m2;		
		ll sol = m2 * x * (q / gcd) + c2;
		int step = mod/gcd;
		if (sol < mod) {
			while (sol < 0) sol += step;
		} else {
			while (sol >= step) sol -= step;
		}
		cout << "The set of all solutions to x == " << c1 << " (mod " << m1 << ") and " << "x == " << c2 << " (mod " << m2 << ") is x == ";
		cout << sol;
		cout << " (mod " << mod << ")\n\n";
	}
}

void non_lin_bf(int a4, int a3, int a2, int a1, int a0, int c, int mod) {
	vector<int> ans;
	for (int x = 0; x < mod; x++) {
		int big_mod = a4*pow(x, 4) + a3*pow(x, 3) + a2*pow(x, 2) + a1*x + a0;
		if ((big_mod - c) % mod == 0) ans.push_back(x);
	}
	if (!ans.size()) {
		cout << "No solution\n\n";
		return;
	}
	cout << "All solutions: x == ";
	for (auto x : ans) cout << x << " ";
	cout << "(mod " << mod << ")\n\n";
}

void addtable(int n) {
	string newline = "\\\\ ";
	string hline = "\\hline";
	cout << "\n\\begin{center}\\begin{tabular}{|c|";
	for (int i = 0; i < n; i++) cout << "c|";
	cout << "}\n";
	cout << hline << "$+$ ";
	for (int i = 0; i < n; i++) {
		cout << "& $[" << i << "]$ ";
	}
	cout << newline << hline << '\n';
	for (int i = 0; i < n; i++) {
		cout << "$[" << i << "]$ & ";
		for (int j = 0; j < n-1; j++)
			cout << "$[" << (i + j) % n << "]$ & ";
		cout << "$[" << (i + n-1) % n << "]$ " << newline << hline << '\n';
	}
	cout << "\\end{tabular}\\end{center}\n\n";
}

void multable(int n) {
	string newline = "\\\\ ";
	string hline = "\\hline";
	cout << "\n\\begin{center}\\begin{tabular}{|c|";
	for (int i = 0; i < n; i++) cout << "c|";
	cout << "}\n";
	cout << hline << "$\\times$ ";
	for (int i = 0; i < n; i++) {
		cout << "& $[" << i << "]$ ";
	}
	cout << newline << hline << '\n';
	for (int i = 0; i < n; i++) {
		cout << "$[" << i << "]$ & ";
		for (int j = 0; j < n-1; j++)
			cout << "$[" << (i * j) % n << "]$ & ";
		cout << "$[" << (i * (n-1)) % n << "]$ " << newline << hline << '\n';
	}
	cout << "\\end{tabular}\\end{center}\n\n";
}

void display() {
	cout << "Choose one:\n";
	cout << "1. Count Divisors\n";
	cout << "2. Extended Euclidian\n";
	cout << "3. Linear Diophantine Equations\n";
	cout << "4. Linear Congruences\n";
	cout << "5. Simultaneous Linear Congruences\n";
	cout << "6. Brute Force Non-Linear Congruences\n";
	cout << "7. Addition Table for Zm\n";
	cout << "8. Multiplication Table for Zm\n";
	cout << '\n';
}

bool ps(long long x) {
	ll s = sqrt(x);
	return x == s * s;
}

int main() {
	int cont = 1;
	ll cnt = 0;
	cout << "----- Welcome to my Algebra Calculator -----\n";
	cout << "Note: '==' represents the \"equivalent\" sign in modular arithmetics\n\n";
	
	while (cont == 1) {
		ll a, b, c;
		display();
		int ans;
		cin >> ans;
		if (ans == 1) {
			cout << "Number to count: ";
			cin >> a;
			cout << "\nThe number of divisors of " << a << " is " << cntdiv(a) << "\n\n";
		}
		else if (ans == 2) {
			cout << "Finding the solution to ax + by = d, where d = gcd(a, b)\n";
			cout << "a, b = ?\n";
			cin >> a >> b;
			eea(a, b);
		}
		else if (ans == 3) {
			cout << "Finding the solution to ax + by = c\n";
			cout << "a, b, c = ?\n";
			cin >> a >> b >> c;
			lde(a, b, c);
		}
		else if (ans == 4) {
			cout << "Finding the solution to ax == c (mod m)\n";
			cout << "a, c, m = ?\n";
			cin >> a >> b >> c;
			lico(a, b, c);
		} 
		else if (ans == 5) {
			cout << "Finding the solution to x == c1 (mod m1) and x == c2 (mod m2)\n";
			cout << "Requires: gcd(m1, m2) = 1\n";
			ll a1, c1, m1, a2, c2, m2;
			cout << "c1, m1 = ?\n";
			cin >> c1 >> m1;
			cout << "c2, m2 = ?\n";
			cin >> c2 >> m2;
			if (gcd(m1, m2) != 1) {
				cout << "Invalid, gcd(m1, m2) != 1.\n\n";
			}
			simlico(c1, m1, c2, m2);
		} 
		else if (ans == 6){
			int a4, a3, a2, a1, a0, c, m;
			cout << "Finding the solution to (a4)x^4 + (a3)x^3 + (a2)x^2 + (a1)x + a0 == c (mod m)\n";
			cout << "a4, a3, a2, a1, a0, c, m = ?\n";
			cin >> a4 >> a3 >> a2 >> a1 >> a0 >> c >> m;
			non_lin_bf(a4, a3, a2, a1, a0, c, m);
		} 
		else if (ans == 7) {
			cout << "Enter number m: ";
			cin >> a;
			addtable(a);
		}
		else if (ans == 8) {
			cout << "Enter number m: ";
			cin >> a;
			multable(a);
		} else {
			cout << "Invalid choice\n\n";
		}
		cout << "Continue?  1 (Yes) / 0 (No)  ";
		cin >> cont;
		if (!cont) {
			cout << "\nThank you!\n";
			return 0;
		}
		cout << "\n\n";
	}
	
	return 0;
}

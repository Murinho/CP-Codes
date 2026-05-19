#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;

const ll M = 1e9 + 9;
const ll p = 2;

struct nodo
{
    nodo *left = nullptr;
    nodo *right = nullptr;
    nodo *next = nullptr;
    ll hash;
    int version = 0;
};

pair<int, nodo *> ejecutar(string prt, nodo *top)
{
    int v = 0;
    nodo *f, *s, *cy, *aux, *cyr;
    for (char c : prt)
    {
        switch (c)
        {
        case 'C':
            f = new nodo();
            s = new nodo();
            v++;

            f->version = v;
            s->version = v;

            f->left = top->left;
            f->right = top->right;

            s->left = top->left;
            s->right = top->right;
            s->next = top->next;
            f->next = s;

            f->hash=top->hash;
            s->hash=top->hash;

            top = f;

            break;
        case 'D':
            top = top->next;
            break;
        case 'L':
            if (top->left == nullptr)
            {
                return {1, top};
            }
            if (top->version)
            {
                cy = new nodo();
                cy->version = top->version;
                cy->hash = top->left->hash;
                cy->left = top->left->left;
                cy->right = top->left->right;
                cy->next = top->next;
                top = cy;
            }
            else
            {
                top->left->next = top->next;
                top = top->left;
            }

            break;
        case 'P':

            f = new nodo();

            f->left = top;
            f->right = top->next;
            f->next = top->next->next;
            f->hash = top->hash + top->next->hash * p;
            f->hash %= M;
            top = f;

            break;
        case 'R':

            if (top->right == nullptr)
            {
                return {1, top};
            }
            if (top->version)
            {
                cy = new nodo();
                cy->version = top->version;
                cy->hash = top->right->hash;
                cy->left = top->right->left;
                cy->right = top->right->right;
                cy->next = top->next;
                top = cy;
            }
            else
            {
                top->right->next = top->next;
                top = top->right;
            }

            break;
        case 'S':
            aux = top->next;
            top->next = top->next->next;
            aux->next = top;
            top = aux;

            break;
        case 'U':
            if (top->left == nullptr)
            {
                return {1, top};
            }

            if (top->version)
            {
                cyr = new nodo();

                cy = new nodo();

                cyr->version = top->version;
                cyr->hash = top->right->hash;
                cyr->left = top->right->left;
                cyr->right = top->right->right;
                cyr->next = top->next;

                cy->version = top->version;
                cy->hash = top->left->hash;
                cy->left = top->left->left;
                cy->right = top->left->right;
                cy->next = cyr;

                top = cy;
            }
            else
            {
                top->right->next = top->next;
                top->left->next = top->right;
                top = top->left;
            }

            break;
        }
    }

    return {0, top};
}

int main()
{
    fast;

    auto top = new nodo();
    top->hash = 1;

    auto prev = top;

    for (int i = 0; i < 1e4 + 5; i++)
    {
        auto nuevo = new nodo();
        nuevo->hash = prev->hash * p % M;
        prev->next = nuevo;
        prev = nuevo;
    }

    auto top2 = new nodo();
    top2->hash = 1;

    auto prev2 = top2;

    for (int i = 0; i < 1e4 + 5; i++)
    {
        auto nuevo = new nodo();
        nuevo->hash = prev2->hash * p % M;
        prev2->next = nuevo;
        prev2 = nuevo;
    }

    string x, y;

    cin >> x >> y;

    auto r1 = ejecutar(x, top);
    auto r2 = ejecutar(y, top2);

    if (r1.first && r2.first)
    {
        cout << "True\n";
        return 0;
    }

    if (r1.first || r2.first)
    {
        cout << "False\n";
        return 0;
    }

    while (true)
    {
        //cout << r1.second->hash << " " << r2.second->hash << "\n";
        if (r1.second == nullptr && r2.second == nullptr)
        {
            cout << "True\n";
            break;
        }
        if (r1.second == nullptr || r2.second == nullptr)
        {
            cout << "False\n";
            break;
        }
        if (r1.second->hash != r2.second->hash)
        {
            cout << "False\n";
            break;
        }
        r1.second = r1.second->next;
        r2.second = r2.second->next;
    }

    return 0;
}
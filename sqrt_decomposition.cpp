/* Mo's Algorithms or sqrt sqrt decomposition

   tutorial: https://blog.anudeep2011.com/mos-algorithm/
*/

bool sqrtSort(query a, query b) {
    if (a.l/316 != b.l/316) // sqrt(100000) ~ 316 or sqrt(n)
        return a.l < b.l;
    return a.r < b.r;
}

void add(int dx) {
    // increament
}

void remove(int dx) {
    // decreament
}

int main()
{
    // query on form [q.l, q.r[
    sort(all(queries), sqrtSort);
    int L = 0, R = 0;
    for(auto q : queries) {
        while (L < q.l)
            remove(L++);
        while (L > q.l)
            add(--L);
        while (R < q.r)
            add(R++);
        while (R > q.r)
            remove(--R);
        // answer in ans array
    }
}

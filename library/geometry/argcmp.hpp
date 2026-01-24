struct Point {
    long long x, y;
};

// arg(p) < arg(q) のとき true
// 偏角は [0, 2π) の範囲でとる
bool argcmp(const Point& p, const Point& q) {
    bool bp = p.y > 0 || (p.y == 0 && p.x > 0);
    bool bq = q.y > 0 || (q.y == 0 && q.x > 0);
    if (bp != bq) return bp;
    return p.x * q.y - p.y * q.x > 0;
}

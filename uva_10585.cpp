#include <iostream> 
#include <stack> 
#include <cstdlib>
#include <cstdio>

using namespace std; 
using ll = long long int;
using llu = unsigned long long int;

/* **************************** Convex Hull ********************************* * 
 * * courtesy of https://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/
 */
struct Point 
{ 
    ll x, y; 
}; 
  
Point p0; 
  
// A utility function to find next to top in a stack 
Point nextToTop(stack<Point> &S) 
{ 
    Point p = S.top(); 
    S.pop(); 
    Point res = S.top(); 
    S.push(p); 
    return res; 
} 
  
// A utility function to swap two points 
void swap(Point &p1, Point &p2) 
{ 
    Point temp = p1; 
    p1 = p2; 
    p2 = temp; 
} 
  
// A utility function to return square of distance 
// between p1 and p2 
llu distSq(Point p1, Point p2) 
{ 
    return static_cast<llu>((p1.x - p2.x))*(p1.x - p2.x) + 
           static_cast<llu>((p1.y - p2.y))*(p1.y - p2.y); 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
ll orientation(Point p, Point q, Point r) 
{ 
    ll val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0LL) return 0LL;  // colinear 
    return (val > 0LL)? 1LL: 2LL; // clock or counterclock wise 
} 
  
// A function used by library function qsort() to sort an array of 
// points with respect to the first point 
int compare(const void *vp1, const void *vp2) 
{ 
   Point *p1 = (Point *)vp1; 
   Point *p2 = (Point *)vp2; 
  
   // Find orientation 
   ll o = orientation(p0, *p1, *p2); 
   if (o == 0LL) 
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 
  
   return (o == 2LL)? -1: 1; 
}

stack<Point> convexHull(Point points[], int n) 
{ 
   ll ymin = points[0].y, min = 0LL; 
   for (int i = 1; i < n; i++) 
   { 
     ll y = points[i].y; 
  
     if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) 
        ymin = points[i].y, min = i; 
   } 
  
   swap(points[0], points[min]); 
   p0 = points[0]; 
   qsort(&points[1], n-1, sizeof(Point), compare); 
  
   int m = 1; // Initialize size of modified array 
   for (int i=1; i<n; i++) 
   { 
       while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0LL) i++; 
          
       points[m] = points[i]; 
       m++;
   } 
  
   if (m < 3) return stack<Point>(); 
  
   stack<Point> S; 
   S.push(points[0]); 
   S.push(points[1]); 
   S.push(points[2]); 
  
   for (int i = 3; i < m; i++) 
   { 
      while (orientation(nextToTop(S), S.top(), points[i]) != 2) S.pop(); 
      S.push(points[i]); 
   } 
  
    return S;
} 
/* ************************************************************************** */

int main ()
{
    Point points[10000], tmp_pts[10000];
    int c;
    ll n, convxhull_size;
    Point pt, center;

    cin >> c;
    while (c--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> pt.x >> pt.y;
            points[i].x = tmp_pts[i].x = pt.x;
            points[i].y = tmp_pts[i].y = pt.y;
        }

        if (n < 3)
        {
            puts("yes");
            continue;
        }

        // center of symmetry should be valid for every point on the 
        // convex hull of S, so the centroid of the convext hull is the only
        // valid guess for us.
        stack<Point> convexhull = convexHull(tmp_pts, n);
        convxhull_size = convexhull.size();

        center.x = 0;
        center.y = 0;
        while (!convexhull.empty())
        {
            pt = convexhull.top();
            center.x += pt.x;
            center.y += pt.y;
            convexhull.pop();
        }

        if (center.x % convxhull_size != 0 || center.y % convxhull_size != 0)
        {
            puts("no");
            continue;
        }
        center.x /= convxhull_size;
        center.y /= convxhull_size;

        // we have to make sure this is the center for the inner points as well.
        // sum of all manhattan distance from each point to the center should be zero.
        // each point should be canceled by it's appropriate pair.
        Point md_sum;
        md_sum.x = md_sum.y = 0LL;
        for (int i = 0; i < n; i++)
        {
            md_sum.x += center.x - points[i].x;
            md_sum.y += center.y - points[i].y; 
        }

        if (md_sum.x == 0LL && md_sum.y == 0LL) puts("yes");
        else puts("no");
    }
    return 0;
}
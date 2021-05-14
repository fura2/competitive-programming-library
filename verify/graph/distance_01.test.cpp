#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2945"

#include "../../library/template.hpp"
#include "../../library/graph/distance_01.hpp"

int main(){
	while(1){
		int n; scanf("%d",&n);
		if(n==0) break;
		int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d); a--; b--;

		int h=100,w=100;
		vector B(h,vector(w,1));
		for(int i=a;i<c;i++) for(int j=b;j<d;j++) B[i][j]=0;

		weighted_graph<int> G(h*w);
		rep(i,h) rep(j,w) {
			if(i<h-1){
				add_directed_edge(G,i*w+j,(i+1)*w+j,B[i+1][j]);
				add_directed_edge(G,(i+1)*w+j,i*w+j,B[i][j]);
			}
			if(j<w-1){
				add_directed_edge(G,i*w+j,i*w+(j+1),B[i][j+1]);
				add_directed_edge(G,i*w+(j+1),i*w+j,B[i][j]);
			}
		}

		int ans=0;
		int x0,y0; scanf("%d%d",&x0,&y0); x0--; y0--;
		rep(i,n){
			int x1,y1; scanf("%d%d",&x1,&y1); x1--; y1--;
			ans+=distance_01(G,x0*w+y0)[x1*w+y1];
			x0=x1;
			y0=y1;
		}
		printf("%d\n",ans);
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
//Da thuc bac 2 co dang ax^2+bx+c;
struct DATHUC{
	int a, b, c;
};

//Da thuc bac 4 co dang mx^4+nx^3+px^2+qx+r;
struct DATHUCBAC4{
	int m,n,p,q,r;
};

void NhapDT(DATHUC &x){
	cin >> x.a >> x.b >> x.c;
}

void KTdau(int x, int before, string bien = ""){
	if (x!=0 && before !=0 ){
		if (x<0 && x!= -1 ) cout << x ;
		else 
			if (x>0 && x!= 1 ) cout << "+" << x ;
		else {
			switch (x){
				case 1: cout << "+" ; 
					if (bien.empty()) cout<<1;
					break;
				case -1: cout << "-" ;
					if (bien.empty()) cout<<1;
					break;
			}
		}
		if (!bien.empty()) cout<<bien;
	}
	else if (x!=0 && before == 0){
			if (x<0 && x!= -1 && x!=1) cout << x ;
		else {
			switch (x){
				case 1: if (bien.empty()) cout<<1;
						break;
				case -1: cout << "-" ;
					if (bien.empty()) cout<<1;
					break;
			}
		}
		if (!bien.empty()) cout<<bien;
	}
}

void XuatDT(DATHUC x){
	if (x.a != 0){
		switch (x.a){
				case 1: cout << "x^2"; break;
				case -1: cout << "-x^2" ; break;
				default: cout << x.a << "x^2"; break;
			}
	}
	KTdau(x.b,x.a,"x");
	KTdau(x.c,x.b);
	cout<<endl;
}

void XuatDTBAC4(DATHUCBAC4 x){
	if (x.m != 0){
		switch (x.m){
				case 1: cout << "x^4"; break;
				case -1: cout << "-x^4" ; break;
				default: cout << x.m << "x^4"; break;
			}
	}
	KTdau(x.n,x.m,"x^3");
	KTdau(x.p,x.n,"x^2");
	KTdau(x.q,x.p,"x");
	KTdau(x.r,x.q);
	cout<<endl;
}

DATHUC Tong2DT(DATHUC x1, DATHUC x2){
	DATHUC Tong;
	Tong.a = x1.a + x2.a;
	Tong.b = x1.b + x2.b;
	Tong.c = x1.c + x2.c;
	return Tong;
}

DATHUC Hieu2DT(DATHUC x1, DATHUC x2){
	DATHUC Hieu;
	Hieu.a = x1.a - x2.a;
	Hieu.b = x1.b - x2.b;
	Hieu.c = x1.c - x2.c;
	return Hieu;
}

DATHUCBAC4 Tich2DT(DATHUC x1, DATHUC x2){
	DATHUCBAC4 Tich;
	Tich.m = x1.a * x2.a;
	Tich.n = x1.a*x2.b + x1.b*x2.a;
	Tich.p = x1.b*x2.b + x1.a*x2.c + x2.a*x1.c;
	Tich.q = x1.b*x2.c + x2.b*x1.c;
	Tich.r = x1.c * x2.c;
	return Tich;
}

int Tinh(int x,DATHUC f){
	return f.a*x*x + f.b*x + f.c;
}

int main(){
	DATHUC x1, x2;
	cout<<"Nhap vao da thuc 1 f1(x) = ( _x^2 + _x + _ ): ";
	NhapDT(x1);
	cout<<"Nhap vao da thuc 2 f2(x) = ( _x^2 + _x + _ ): ";
	NhapDT(x2);
	
	cout << "Tong cac da thuc la: \t";
	DATHUC Tong = Tong2DT(x1,x2);
	XuatDT(Tong);
	
	cout << "Hieu cac da thuc la: \t";
	DATHUC Hieu = Hieu2DT(x1,x2);
	XuatDT(Hieu);
	
	cout << "Tich cac da thuc la: \t";
	DATHUCBAC4 Tich = Tich2DT(x1,x2);
	XuatDTBAC4(Tich);
	
	// Tinh f1 f2 nhap tu ban phim 
	int x;
	cout << "Gia tri cac da thuc khi x = ";
	cin>>x;
	cout <<"f1(" << x << ") = " << Tinh(x,x1) << endl;
	cout <<"f2(" << x << ") = "<< Tinh(x,x2) << endl;
	return 0;
}

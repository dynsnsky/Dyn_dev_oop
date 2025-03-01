#include <iostream>
#include <cmath>
using namespace std;

struct SoPhuc{
    double thuc,ao;
};

void Nhap(SoPhuc &s){
    cout << "\tPhan thuc: "; cin >> s.thuc;
    cout << "\tPhan ao: "; cin >> s.ao;
}

void InSP(SoPhuc s){
    if (s.thuc !=0)
        cout<<s.thuc;
    if (s.ao>0)
        cout<<"+"<<s.ao<<"i";
    else if (s.ao<0)
        cout<<s.ao<<"i";
    cout<<endl;
}

SoPhuc Cong(const SoPhuc& sp1, const SoPhuc& sp2) {
    return {sp1.thuc + sp2.thuc, sp1.ao + sp2.ao};
}

SoPhuc Tru(const SoPhuc& sp1, const SoPhuc& sp2) {
    return {sp1.thuc - sp2.thuc, sp1.ao - sp2.ao};
}

SoPhuc Nhan(const SoPhuc& sp1, const SoPhuc& sp2) {
    return {sp1.thuc * sp2.thuc - sp1.ao * sp2.ao, sp1.thuc * sp2.ao + sp1.ao * sp2.thuc};
}

SoPhuc Chia(const SoPhuc& sp1, const SoPhuc& sp2) {
    double mau = sp2.thuc * sp2.thuc + sp2.ao * sp2.ao;
    return {(sp1.thuc * sp2.thuc + sp1.ao * sp2.ao) / mau, (sp1.ao * sp2.thuc - sp1.thuc * sp2.ao) / mau};
}

int main(){
    SoPhuc sp1,sp2;
    cout<<"Nhap vao so phuc thu nhat\n"; 
        Nhap(sp1);
    cout<<"Nhap vao so phuc thu hai\n"; 
        Nhap(sp2);
    cout<<"Tong 2 so phuc: ";
        InSP(Cong(sp1,sp2));
    cout<<"Hieu 2 so phuc: ";
        InSP(Tru(sp1,sp2));
    cout<<"Tich 2 so phuc: ";
        InSP(Nhan(sp1,sp2));
    cout<<"Thuong 2 so phuc: ";
        InSP(Chia(sp1,sp2));
    return 0;
}
#include <iostream>
#include <stdlib.h>
#include "multilinkedlist.h"

using namespace std;

infotype_mhs x;
infotype_ukm y;
list_mhs L1;
list_ukm L2;
adr_mhs P;
adr_ukm R;
adr_keikutsertaan Q;
int pilih ;
string nim,nama,kodeukm;

void create ()
{
    create_elm_mhs(L1);
    create_elm_ukm(L2);
    menu();
}
void kembali ()
{
    cout<<" 1.kembali ke menu "<<endl;
    cout<<" 2.exit"<<endl;
    cout<<"pilih : ";
    cin>>pilih;

    if (pilih==1)
    {
        menu();
    }
}
bool ceknim (adr_mhs P,string nim)
{

    if (P==NULL)
    {
        return false;
    }
    else
    {
        while ((P!=NULL)&&(info(P).nim!=nim))
        {
            P=next(P);
        }
        if (P==NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
bool cekkodeukm (adr_ukm R,string kode_ukm)
{
    if (R==NULL)
    {
        return false;
    }
    else
    {
        while ((R!=NULL)&&(info(R).kode_ukm!=kode_ukm))
        {
            R=next(R);
        }
        if (R==NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
bool cekanak(adr_keikutsertaan Q,string kode_ukm)
{
    if (Q==NULL)
    {
        return false;
    }
    else
    {
        while ((Q!=NULL)&&(info(info(Q)).kode_ukm!=kode_ukm))
        {
            Q=next(Q);
        }
        if (Q==NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

void menu()
{
    system("CLS");
    cout<<"        PROGRAM TUBES        "<<endl;
    cout<<"============================="<<endl;
    cout<<"            MENU             "<<endl;
    cout<<"1. Input data    "<<endl; //berdasarkan ascending angkatan
    cout<<"2. Delete data   "<<endl;
    cout<<"3. Mengupdate data"<<endl; //dapat mengubah data mahasiswa berupa nama dan nim berdasarkan NIM mahasiswa
    cout<<"4. Searching data "<<endl; //Menampilkan data mahasiswa tertentu berupa nama , nim , angkatan berdasarkan NIM
    cout<<"5. View data "<<endl;
    cout<<"6. report "<<endl;
    cout<<"PILIH : ";
    cin>>pilih;
    cout<<endl;
    if (pilih == 1)
    {
        cout<<"1.Input data mahasiswa baru "<<endl;
        cout<<"2.Input data UKM baru "<<endl;
        cout<<"3.Input data UKM mahasiswa"<<endl;
        cout<<"pilih : ";
        cin>>pilih;
        if (pilih==1)
        {
            P=first(L1);
            cout<<"Masukkan inputan "<<endl;
            cout<<"NIM : ";
            cin>>(nim);
            if (ceknim(P,nim)==false)
            {
                x.nim=nim;
                cout<<"Nama : ";
                cin>>(x.nama);
                cout<<"Angkatan : ";
                cin>>(x.angkatan);
                cout<<endl;
                P = alokasi1(x);
                ascending(L1,P);
            }
            else
            {
               cout<<"NIM sudah digunakan"<<endl;
            }
        }
        else if (pilih==2)
        {
            R=first(L2);
            cout<<"Masukkan inputan "<<endl;
            cout<<"kode UKM : ";
            cin>>(kodeukm);
            if (cekkodeukm(R,kodeukm)==false)
            {
                y.kode_ukm=kodeukm;
                cout<<"nama UKM : ";
                cin>>(y.nama_ukm);
                R = alokasi3(y);
                insertfirstukm(L2,R);
            }
            else
            {
                cout<<"kode sudah digunakan "<<endl;
            }
        }
        else if (pilih==3)
        {
           if ((first(L1)!=NULL)&&(first(L2)!=NULL))
             {
                cout<<"Masukkan NIM : ";
                cin>>nim;
                P = first(L1);
                while ((next(P)!=NULL)&&(info(P).nim!=nim))
                {
                    P=next(P);
                }
                if (info(P).nim==nim)
                {
                    Q=firstanak(P);
                    cout<<"Masukkan kode UKM : ";
                    cin>>kodeukm;
                    if (cekanak(Q,kodeukm)==false)
                    {
                        penghubung (P,L2,kodeukm);
                    }
                    else
                    {
                        cout<<"UKM sudah anda daftarkan"<<endl;
                    }
                }
                else
                {
                    cout<<"NIM tidak ada"<<endl;
                }
             }
            else
            {
                cout<<"data LIST MAHASISWA atau UKM kosong"<<endl;
            }
        }
        else
        {
            cout<<"format salah"<<endl;
        }
    }

    else if (pilih == 2)
        {
            cout<<"  MENU DELETE "<<endl;
            cout<<"1.delete mahasiswa "<<endl;
            cout<<"2.delete UKM mahasiswa "<<endl;
            cout<<"3.delete UKM "<<endl;
            cout<<"4.pilih : ";
            cin>>pilih;
            if (pilih==1)
            {
                    cout<<" masukkan nim : ";
                    cin>>nim;
                    deletemhs(L1,nim);
            }
            else if  (pilih==2)
            {

            }
            else if (pilih==3)
            {
                    cout<<" masukkan kode ukm : ";
                    cin>>kodeukm;
                    deleteukm(L2,kodeukm);
            }
        }
    else if (pilih==3)
        {
                update(L1);
        }
    else if (pilih==4)
        {
            string nim;
            if (first(L1)==NULL)
            {
                cout<<"LIST MASIH KOSONG"<<endl;
            }
            else
            {
                cout<<"MASUKKAN NIM : ";
                cin>>nim;
                searching(L1,nim);
            }
        }
    else if (pilih==5)
        {
            view(L1,L2);
        }
    else if (pilih==6)
        {
            report(L1,L2);
        }
    else
        {
            cout<<"SALAH FORMAT"<<endl;
        }
kembali();
}
void create_elm_mhs (list_mhs &L1)
{
    first(L1) = NULL;
    last(L1)= NULL;
}
void create_elm_ukm (list_ukm &L2)
{
    first(L2)= NULL;
    last (L2)= NULL;
}
adr_mhs alokasi1(infotype_mhs x)
{
    adr_mhs P = new elm_mhs;
    next(P)=NULL;
    prev(P)=NULL;
    info(P)=x;
    firstanak(P)=NULL;
    lastanak(P)=NULL;
    return P;
}
adr_keikutsertaan alokasi2 (adr_ukm x)
{
    adr_keikutsertaan P=new elm_keikutsertaan;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}
adr_ukm alokasi3 (infotype_ukm x)
{
    adr_ukm P = new elm_ukm;
    next(P)=NULL;
    prev(P)=NULL;
    info(P)=x;
    return P;
}

void insertfirst (list_mhs &L1 , adr_mhs P )
{

    if (first(L1)==NULL)
    {
      first(L1)=P;
      last(L1)=P;

    }
    else
    {
        next(P)=(first(L1));
        prev(first(L1))=P;
        first(L1)=P;
    }
}
void insertlast (list_mhs &L1 , adr_mhs P )
{
    if (first(L1)==NULL)
    {
        first(L1)=P;
        last(L1)=P;
    }
    else
    {
        next(last(L1))=P;
        prev(P)=last(L1);
        last(L1)=P;
    }
}
void insertafter (list_mhs &L1,adr_mhs P,adr_mhs prec)
{
    if (first(L1)==NULL)
    {
        first(L1)=P;
        last(L1)=P;
    }
    else
    {
        next(P)=next(prec);
        prev(next(prec))=P;
        next(prec)=P;
        prev(P)=prec;
    }
}
void insertfirstukm (list_ukm,adr_ukm P)
{
    if (first(L2)==NULL)
    {
        first(L2)=P;
        last(L2)=P;
    }
    else
    {
        next(P)=first(L2);
        prev(first(L2))=P;
        first(L2)=P;
    }
}
void ascending (list_mhs &L1 , adr_mhs P)
{

    adr_mhs q;
    q=first(L1);
    if ((first(L1)==NULL)||(info(P).angkatan<=info(q).angkatan))
    {
        insertfirst(L1,P);
    }
    else if (info(P).angkatan>=info(last(L1)).angkatan)
    {
        insertlast(L1,P);
    }
    else
    {
        adr_mhs q;
        q=first(L1);
        while (info(next(q)).angkatan<info(P).angkatan)
        {
            q=next(q);
        }
        if (info(next(q)).angkatan>info(P).angkatan)
        {
            insertafter(L1,P,q);
        }
    }

}
void deletemhs (list_mhs &L1 , string nim )
{
    adr_mhs q,r,z;
    z=first(L1);
    if (first(L1)==NULL)
    {
        cout<<"list kosong"<<endl;
    }
    else
    {
        while ((info(z).nim!=nim)&&(next(z)!=NULL))
        {
                z=next(z);
        }
        if(info(z).nim!=nim)
        {
            cout<<"NIM TIDAK ADA"<<endl;
        }
        else if (first(L1)==last(L1))
        {
            q=first(L1);
            first(L1)=NULL;
            last(L1)=NULL;
            delete q;
        }
        else if  (info(last(L1)).nim==nim)
        {
            q=last(L1);
            last(L1)=prev(last(L1));
            next(last(L1))=NULL;
            delete q;
        }
        else if  (info(first(L1)).nim==nim)
        {
            q=first(L1);
            first(L1)=next(first(L1));
            prev(first(L1))=NULL;
            delete q;
        }
        else
        {
            q=first(L1);
            while ((info(q).nim!=nim )&&(next(q)!=NULL))
            {
                q=next(q);
            }
            if (info(q).nim==nim)
            {
                r=q;
                next(prev(r))=next(r);
                prev(next(r))=prev(r);
                prev(r)=NULL;
                next(r)=NULL;
                delete r;
            }
        }
    }
}

void deleteukm (list_ukm &L2 , string kode_ukm)
{
    adr_ukm q,r,z;
    z=first(L2);
    if (first(L2)==NULL)
    {
        cout<<"list kosong"<<endl;
    }
    else
    {
        while ((info(z).kode_ukm!=kode_ukm)&&(next(z)!=NULL))
        {
                z=next(z);
        }
        if(info(z).kode_ukm!=kode_ukm)
        {
            cout<<"NIM TIDAK ADA"<<endl;
        }
        else if (first(L2)==last(L2))
        {
            q=first(L2);
            first(L2)=NULL;
            last(L2)=NULL;
            delete q;
        }
        else if  (info(last(L2)).kode_ukm==kode_ukm)
        {
            q=last(L2);
            last(L2)=prev(last(L2));
            next(last(L2))=NULL;
            delete q;
        }
        else if  (info(first(L2)).kode_ukm==kode_ukm)
        {
            q=first(L2);
            first(L2)=next(first(L2));
            prev(first(L2))=NULL;
            delete q;
        }
        else
        {
            q=first(L2);
            while ((info(q).kode_ukm!=kode_ukm )&&(next(q)!=NULL))
            {
                q=next(q);
            }
            if (info(q).kode_ukm==kode_ukm)
            {
                r=q;
                next(prev(r))=next(r);
                prev(next(r))=prev(r);
                prev(r)=NULL;
                next(r)=NULL;
                delete r;
            }
        }
    }
}
void update (list_mhs &L1)
{
    cout<<"YUK UPDATE DATA MAHASISWA"<<endl;
    cout<<"1. UPDATE NIM"<<endl;
    cout<<"2. UPDATE NAMA"<<endl;
    cout<<"pilih : ";
    cin>>pilih;
    cout<<"masukkan NIM anda : " ;
    cin>>nim;

    adr_mhs q;
    q=first(L1);
    if (first(L1)==NULL)
    {
        cout<<"LIST KOSONG "<<endl;
    }
    else
    {
        while ((next(q)!=NULL)&&(info(q).nim!=nim))
        {
            q=next(q);
        }
        if (info(q).nim!=nim)
        {
            cout<<"NIM TIDAK ADA"<<endl;
        }
        else
        {
                if (pilih==1)
                {
                    cout<<"masukkan NIM baru : ";
                    cin>>nim;
                    info(q).nim=nim;
                }
                else if (pilih==2)
                {
                    cout<<"masukkan nama baru : ";
                    cin>>nama;
                    info(q).nama=nama;
                }
                else
                {
                    cout<<"SALAH FORMAT"<<endl;
                }
        }
    }
}
void view (list_mhs L1,list_ukm L2)
{
    cout<<"VIEW"<<endl;
    cout<<"1.data mahasiswa"<<endl;
    cout<<"2.data UKM"<<endl;
    cout<<"3.data setiap mahasiswa beserta UKM yang diambil ";
    cout<<"4.anggota UKM "<<endl;
    cout<<"pilih : ";
    cin>>pilih;
    if (pilih==1)
        {
            if ((first(L1)==NULL)&&(last(L1)==NULL))
            {
                cout<<"LIST KOSONG"<<endl;
            }
            else
            {
            adr_mhs P=first(L1);
            while (P!=NULL)
            {
                cout<<"Nim  : "<<info(P).nim<<endl;
                cout<<"Nama : "<<info(P).nama<<endl;
                cout<<"Angkatan : "<<info(P).angkatan<<endl;
                cout<<"JUMLAH UKM : "<<info(P).jum_ukm<<endl<<endl;
                P=next(P);
            }
            }
        }
    else if (pilih==2)
        {
            if ((first(L2)==NULL)&&(last(L2)==NULL))
            {
                cout<<"LIST KOSONG"<<endl;
            }
            else
            {
            adr_ukm P=first(L2);
            while (P!=NULL)
            {
                cout<<"Kode UKM : "<<info(P).kode_ukm<<endl;
                cout<<"Nama UKM : "<<info(P).nama_ukm<<endl;
                cout<<"JUMLAH ANGGOTA : "<<info(P).jum_mhs<<endl;
                P=next(P);
            }
            }
        }
   else if (pilih==3)
        {
            P=first(L1);
            while (P!=NULL)
            {
                    cout<<endl;
                    cout<<"Nim  : "<<info(P).nim<<endl;
                    cout<<"DAFTAR UKM yang diambil : "<<endl;
                    adr_keikutsertaan X;
                    X=firstanak(P);
                    if (X==NULL)
                    {
                       cout<<"tidak ada ukm"<<endl;
                    }
                    else
                    {
                        while ((X)!=lastanak(P))
                        {
                            cout<<"Nama UKM : "<<info(info(X)).nama_ukm<<endl;
                            X=next(X);
                        }
                        if ((X)==lastanak(P))
                        {
                             cout<<"Nama UKM : "<<info(info(X)).nama_ukm<<endl;
                        }
                    }
                P=next(P);
            }
        }
    else if (pilih==4)
    {

    }
    else
        {
            cout<<"SALAH FORMAT"<<endl;
        }
    kembali();
}

void searching (list_mhs L1 , string nim)
{
    adr_mhs q;
    q=first(L1);
    while ((next(q)!=NULL)&&(info(q).nim!=nim))
    {
        q=next(q);
    }
    if (info(q).nim!=nim)
    {
        cout<<"NIM TIDAK ADA"<<endl;
    }
    else
        {
            cout<<"Nim  : "<<info(q).nim<<endl;
            cout<<"Nama : "<<info(q).nama<<endl;
            cout<<"Angkatan : "<<info(q).angkatan<<endl<<endl;
        }
    kembali();
}
void penghubung(adr_mhs P,list_ukm L2 , string kodeukm)
{
    adr_mhs Z;
    adr_ukm q;
    q=first(L2);
    while ((next(q)!=NULL)&&(info(q).kode_ukm!=kodeukm))
    {
            q=next(q);
    }
    if (info(q).kode_ukm!=kodeukm)
    {
        cout<<"kode tidak ditemukan "<<endl;
    }
    else
    {

        Q=alokasi2 (q);
        if (firstanak(P)==NULL)
        {
            firstanak(P)=Q;
            lastanak(P)=Q;
        }
        else
        {
            next(lastanak(P))=Q;
            prev(Q)=lastanak(P);
            lastanak(P)=Q;
            next(lastanak(P))=firstanak(P);
            prev(firstanak(P))=lastanak(P);

        }
        info(P).jum_ukm=info(P).jum_ukm+1;
        info(q).jum_mhs=info(q).jum_mhs+1;
    }

}
void report (list_mhs L1,list_ukm L2)
{

    P=first(L1);
    R=first(L2);
    int maks=0;
    cout<<"REPORT"<<endl;
    cout<<"1.UKM dengan anggota terbanyak "<<endl;
    cout<<"2.Mahasiswa dengan UKM terbanyak "<<endl;
    cout<<"pilih : ";
    cin>>pilih;
    cout<<endl;
    if (pilih==1)
    {
        while ((R!=NULL)&&(info(R).jum_mhs>maks))
        {
                maks=info(R).jum_mhs;
                R=next(R);
        }
        if (first(L2)==NULL)
        {
            cout<<"LIST UKM KOSONG"<<endl;
        }
        else
        {
            R=first(L2);
            if (maks==0)
            {
                cout<<"SEMUA UKM BELUM MEMPUNYAI ANGGOTA"<<endl;
            }
            else
            {
                while ((R!=NULL)&&(info(R).jum_mhs==maks))
                {
                        cout<<" NAMA UKM : "<<info(R).nama_ukm<<endl;
                        cout<<" KODE : "<<info(R).kode_ukm <<endl;
                        cout<<" Jum.ANGGOTA : "<<info(R).jum_mhs<<endl<<endl;
                        R=next(R);
                }
            }
        }
    }
    else if (pilih==2)
    {
        while ((P!=NULL)&&(info(P).jum_ukm>maks))
        {
                maks=info(P).jum_ukm;
                P=next(P);
        }
        if (first(L1)==NULL)
        {
            cout<<"LIST MAHASISWA KOSONG"<<endl;
        }
        else
        {
            P=first(L1);
            if (maks==0)
            {
                cout<<"SEMUA MAHASISWA BELUM MEMPUNYAI UKM"<<endl;
            }
            else
            {
                while ((P!=NULL)&&(info(P).jum_ukm==maks))
                {
                        cout<<" NAMA : "<<info(P).nama<<endl;
                        cout<<" NIM  : "<<info(P).nim <<endl;
                        cout<<" ANGKATAN : "<<info(P).angkatan<<endl;
                        cout<<" Jum.UKM : "<<info(P).jum_ukm<<endl<<endl;
                        P=next(P);
                }
            }
        }
    }

}

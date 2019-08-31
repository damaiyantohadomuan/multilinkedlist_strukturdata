#ifndef MULTILINKEDLIST_H_INCLUDED
#define MULTILINKEDLIST_H_INCLUDED
#define Nil NULL
#define first(L1) ((L1).first)
#define last(L1)  ((L1).last)
#define first(L2) ((L2).first)
#define last(L2) ((L2).last)
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define next(prec) prec->next
#define firstanak(P) (P)->firstanak
#define lastanak(P) (P)->lastanak


using namespace std;

struct infotype_mhs
{
    string nim;
    string nama;
    int jum_ukm=0;
    int angkatan;
};

struct infotype_ukm
{
    string kode_ukm;
    string nama_ukm;
    int jum_mhs=0;
};

typedef struct elm_mhs *adr_mhs ;
typedef struct elm_ukm *adr_ukm ;
typedef struct elm_keikutsertaan *adr_keikutsertaan ;

struct elm_mhs
{
  infotype_mhs info;
  adr_mhs next;
  adr_mhs prev;
  adr_keikutsertaan firstanak;
  adr_keikutsertaan lastanak;

};

struct elm_keikutsertaan
{
  adr_ukm info;
  adr_keikutsertaan next;
  adr_keikutsertaan prev;
};

struct elm_ukm
{
  infotype_ukm info;
  adr_ukm next;
  adr_ukm prev;
};

struct list_mhs
{
    adr_mhs first;
    adr_mhs last;
};

struct list_ukm
{
    adr_ukm first;
    adr_ukm last;
};

void kembali();
void create ();
void menu();
void create_elm_mhs (list_mhs &L1);
void create_elm_ukm (list_ukm &L2);
adr_mhs alokasi1(infotype_mhs x);
adr_keikutsertaan alokasi2 (adr_ukm x);
adr_ukm alokasi3(infotype_ukm x);
void insertfirst (list_mhs &L1 , adr_mhs P);
void insertlast (list_mhs &L1 , adr_mhs P );
void ascending (list_mhs &L1 , adr_mhs P);
void deletemhs (list_mhs &L1 , string nim );
void deleteukm (list_ukm &L2 , string kode_ukm);
void insertfirstukm (list_ukm,adr_ukm P);
void update (list_mhs &L1);
void view (list_mhs L1,list_ukm L2);
void searching (list_mhs L1 , string nim);
void report (list_mhs L1,list_ukm L2);
void penghubung (adr_mhs P,list_ukm L2,string kodeukm);
bool ceknim(adr_mhs P,string nim);
bool cekkodeukm (adr_ukm R,string kode_ukm);
bool cekanak(adr_keikutsertaan Q,string kode_ukm);


#endif // MULTILINKEDLIST_H_INCLUDED

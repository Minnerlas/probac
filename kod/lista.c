#include <stdlib.h>
#include <stdio.h>

typedef struct clan {
    int vred;
    struct clan *sledeci;
} Clan;


typedef struct lista {
    int duz;
    Clan *prvi;
} Lista;

Lista* initlista() {
    Lista* lista= (Lista*) malloc(sizeof(Lista));
    lista->duz=0;
    lista->prvi=NULL;
    return lista;
}

void ldodaj(Lista* l,int n){
    Clan *novi=(Clan*)malloc(sizeof(Clan));
    novi->vred=n;
    novi->sledeci=NULL;
    if (l->prvi==NULL){
        l->prvi = novi;
        l->duz=1;
        return;
    }
    Clan *t=l->prvi;
    while(t->sledeci!=NULL)
        t=t->sledeci;
    t->sledeci=novi;
    l->duz++;
}

void lstampaj(Lista *l){
    printf("[");
    Clan *t=l->prvi;
    if(t==NULL){
        printf("]\n");
        return;
    }
    printf("%d",t->vred);
    t=t->sledeci;

    while(t!=NULL){
        printf(", %d",t->vred);
        t=t->sledeci;
    }
    printf("]\n");
}

int main() {

    Lista *lista=initlista();
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        ldodaj(lista,t);
    }
    lstampaj(lista);
    
}
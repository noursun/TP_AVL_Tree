  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  #include <stdio.h>
  #include <stdlib.h>
   int comp_rotation=0;
   int comp_noeud=0;

  typedef int bool ;

  #define True 1
  #define False 0

  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tiii Type_Tiii  ;
  typedef Type_Tiii * Typestr_Tiii ;
  typedef int Type1_Tiii  ;
  typedef int Type2_Tiii  ;
  typedef int Type3_Tiii  ;
  struct Tiii
    {
      Type1_Tiii Champ1 ;
      Type2_Tiii Champ2 ;
      Type3_Tiii Champ3 ;
    };

  Type1_Tiii Struct1_Tiii ( Typestr_Tiii S)
    {
      return  S->Champ1 ;
    }

  Type2_Tiii Struct2_Tiii ( Typestr_Tiii S)
    {
      return  S->Champ2 ;
    }

  Type3_Tiii Struct3_Tiii ( Typestr_Tiii S)
    {
      return  S->Champ3 ;
    }

  void Aff_struct1_Tiii ( Typestr_Tiii S, Type1_Tiii Val )
    {
       S->Champ1 = Val ;
    }

  void Aff_struct2_Tiii ( Typestr_Tiii S, Type2_Tiii Val )
    {
       S->Champ2 = Val ;
    }

  void Aff_struct3_Tiii ( Typestr_Tiii S, Type3_Tiii Val )
    {
       S->Champ3 = Val ;
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tiii Typeelem_ATiii   ;
  typedef struct Noeud_ATiii * Pointeur_ATiii ;

  struct Noeud_ATiii
    {
      Typeelem_ATiii  Val ;
      Pointeur_ATiii Fg ;
      Pointeur_ATiii Fd ;
      Pointeur_ATiii Pere ;
     } ;

  Typeelem_ATiii Info_ATiii( Pointeur_ATiii P )
    { return P->Val;   }

  Pointeur_ATiii Fg_ATiii( Pointeur_ATiii P)
    { return P->Fg ; }

  Pointeur_ATiii Fd_ATiii( Pointeur_ATiii P)
    { return P->Fd ; }

  Pointeur_ATiii Pere_ATiii( Pointeur_ATiii P)
    { return P->Pere ; }

  void Aff_info_ATiii ( Pointeur_ATiii P, Typeelem_ATiii Val)
    {
      Typeelem_ATiii _SSS ;
      _SSS = malloc(sizeof(Typestr_Tiii));
      /* Affectation globale de structure */
      _SSS->Champ1 = Val->Champ1;
      _SSS->Champ2 = Val->Champ2;
      _SSS->Champ3 = Val->Champ3;
      Val = _SSS ;
       P->Val = Val ;
    }

  void Aff_fg_ATiii( Pointeur_ATiii P, Pointeur_ATiii Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATiii( Pointeur_ATiii P, Pointeur_ATiii Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATiii( Pointeur_ATiii P, Pointeur_ATiii Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATiii( Pointeur_ATiii *P)
    {
      *P = (struct Noeud_ATiii *) malloc( sizeof( struct Noeud_ATiii))   ;
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATiii( Pointeur_ATiii P)
    { free( P ) ; }


  /** Implémentation **\: TABLEAU DE ENTIERS**/

  /** Tableaux dynamiques **/
  typedef int Typeelem_W100000i ;
  typedef Typeelem_W100000i *  Pointeur_W100000i;

  void Alloc_tab_W100000i ( Pointeur_W100000i *T )
    { *T = malloc(100000 * sizeof(int)); }

  void Liber_tab_W100000i ( Pointeur_W100000i T)
    { free(T) ;}

  Typeelem_W100000i Element_W100000i ( Pointeur_W100000i V  , int I1  )
    {
      return *(V + I1-1 );
    }

  void Aff_element_W100000i ( Pointeur_W100000i V,  int I1 ,  Typeelem_W100000i Val )
    {
      *(V + I1-1 ) = Val ;
    }


  /** Variables du programme principal **/
  Pointeur_ATiii R;
  int I;
  int N;
  int M;
  int X;
  Pointeur_W100000i Tab;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }

  int Max (int a, int b)
    {
      if (a > b) return(a);
      else return(b);
    }


  /** Initialisation d'une structure **/
  void Init_struct_Tiii ( Typestr_Tiii S, Type_Tiii S_ )
    {
      S->Champ1 = S_.Champ1 ;
      S->Champ2 = S_.Champ2 ;
      S->Champ3 = S_.Champ3 ;
    }


  /** Prototypes des fonctions **/

  void Aleatab (Pointeur_W100000i *T , int *Taille);
  int  Hauteur (Pointeur_ATiii *A) ;
  void Inser_avl (Pointeur_ATiii *R , int *Val);
  void Postordre_avl (Pointeur_ATiii *R);
  void Creer_tab_avl (Pointeur_ATiii *R , Pointeur_W100000i *Tab , int *Taille);
  void Rotation_d (Pointeur_ATiii *A , Pointeur_ATiii *R);
  void Rotation_g (Pointeur_ATiii *A , Pointeur_ATiii *R);
  void Rotation_droite (Pointeur_ATiii *A , Pointeur_ATiii *R);
  void Rotation_gauche (Pointeur_ATiii *A , Pointeur_ATiii *R);
  void Transf_arb_avl (Pointeur_ATiii *A , Pointeur_ATiii *R);
  void Libererarb (Pointeur_ATiii *R);

  void Aleatab (Pointeur_W100000i *T , int *Taille)
    {
      /** Variables locales **/
      int I;

      /** Corps du module **/
     for( I  =  1 ;I <=  *Taille   ; ++I){
       Aff_element_W100000i(*T , I   , Aleanombre(1000000) ) ;

     } ;

    }
  int  Hauteur (Pointeur_ATiii *A)
    {
      /** Variables locales **/
      int  Hauteur2 ;

      /** Corps du module **/
     if( ( *A == NULL )) {
       Hauteur2  =  - 1 ;
       }
     else
       {
       Hauteur2  =  Struct3_Tiii(Info_ATiii(*A )  ) ;

     } ;

     return Hauteur2 ;
    }
  void Inser_avl (Pointeur_ATiii *R , int *Val)
    {
      /** Variables locales **/
      Pointeur_ATiii P;
      Pointeur_ATiii F;
      bool Arret;
      Typestr_Tiii S;
      Type_Tiii S_S;

      /** Corps du module **/
     S = malloc(sizeof(Typestr_Tiii));
     S_S.Champ1 = 0 ;
     S_S.Champ2 = 0 ;
     S_S.Champ3 = 0 ;
     Init_struct_Tiii ( S , S_S )  ;
     if( ( *R == NULL )) {
       Creernoeud_ATiii(&*R ) ;
       Aff_info_ATiii(*R , S ) ;
       Aff_struct1_Tiii(Info_ATiii(*R )  , *Val ) ;
       }
     else
       {
       P  =  *R ;
       Arret  =  False ;
       while( ( Arret == False )) {
         if( ( Struct1_Tiii(Info_ATiii(P )  ) == *Val )) {
           Arret  =  True ;
           }
         else
           {
           if( ( Struct1_Tiii(Info_ATiii(P )  ) > *Val )) {
             if( ( Fg_ATiii(P ) == NULL )) {
               Creernoeud_ATiii(&F ) ;
               Aff_info_ATiii(F , S ) ;
               Aff_fg_ATiii(P , F ) ;
               Aff_struct1_Tiii(Info_ATiii(Fg_ATiii(P ) )  , *Val ) ;
               Aff_pere_ATiii(Fg_ATiii(P ) , P ) ;
               Arret  =  True ;
               }
             else
               {
               P  =  Fg_ATiii(P ) ;

             } ;
             }
           else
             {
             if( ( Fd_ATiii(P ) == NULL )) {
               Creernoeud_ATiii(&F ) ;
               Aff_info_ATiii(F , S ) ;
               Aff_fd_ATiii(P , F ) ;
               Aff_struct1_Tiii(Info_ATiii(Fd_ATiii(P ) )  , *Val ) ;
               Aff_pere_ATiii(Fd_ATiii(P ) , P ) ;
               Arret  =  True ;
               }
             else
               {
               P  =  Fd_ATiii(P ) ;

             } ;

           } ;

         } ;

       } ;

     } ;

    }
  void Postordre_avl (Pointeur_ATiii *R)
    {
      /** Variables locales **/
      Pointeur_ATiii _Px1;
      Pointeur_ATiii _Px2;

      /** Corps du module **/
     if( ( *R != NULL )) {
       _Px1 =  Fg_ATiii(*R ) ;
       Postordre_avl ( &_Px1) ;
       _Px2 =  Fd_ATiii(*R ) ;
       Postordre_avl ( &_Px2) ;
       printf ( " %d", Struct1_Tiii(Info_ATiii(*R)) ) ;
       printf ( " %s", "" ) ;

     } ;

    }
  void Creer_tab_avl (Pointeur_ATiii *R , Pointeur_W100000i *Tab , int *Taille)
    {
      /** Variables locales **/
      int I;
      int _Px1;

      /** Corps du module **/
     for( I  =  1 ;I <=  *Taille   ; ++I){
       _Px1 =  Element_W100000i(*Tab , I   ) ;
       Inser_avl ( & *R , &_Px1) ;

     } ;

    }
  void Rotation_d (Pointeur_ATiii *A , Pointeur_ATiii *R)
    {
      /** Variables locales **/
      Pointeur_ATiii F;
      Pointeur_ATiii _Px1;
      Pointeur_ATiii _Px2;
      Pointeur_ATiii _Px3;
      Pointeur_ATiii _Px4;
      Pointeur_ATiii _Px5;
      Pointeur_ATiii _Px6;
      Pointeur_ATiii _Px7;
      Pointeur_ATiii _Px8;
      Pointeur_ATiii _Px9;
      Pointeur_ATiii _Px10;
      Pointeur_ATiii _Px11;
      Pointeur_ATiii _Px12;

      /** Corps du module **/
      comp_rotation ++;
     F  =  Fg_ATiii(*A ) ;
     comp_noeud ++;
     Aff_fg_ATiii(*A , Fd_ATiii(F ) ) ;
     Aff_fd_ATiii(F , *A ) ;
     if( ( Fg_ATiii(*A ) != NULL )) {
       Aff_pere_ATiii(Fg_ATiii(*A ) , *A ) ;

     } ;
     _Px1 =  Fg_ATiii(*A ) ;
     _Px2 =  Fd_ATiii(*A ) ;
     Aff_struct3_Tiii(Info_ATiii(*A )  , Max(Hauteur ( &_Px1) , Hauteur ( &_Px2) ) + 1 ) ;
     _Px3 =  Fg_ATiii(*A ) ;
     _Px4 =  Fd_ATiii(*A ) ;
     Aff_struct2_Tiii(Info_ATiii(*A )  , Hauteur ( &_Px3) - Hauteur ( &_Px4) ) ;
     _Px5 =  Fd_ATiii(F ) ;
     _Px6 =  Fg_ATiii(F ) ;
     Aff_struct3_Tiii(Info_ATiii(F )  , Max(Hauteur ( &_Px5) , Hauteur ( &_Px6) ) + 1 ) ;
     _Px7 =  Fg_ATiii(F ) ;
     _Px8 =  Fd_ATiii(F ) ;
     Aff_struct2_Tiii(Info_ATiii(F )  , Hauteur ( &_Px7) - Hauteur ( &_Px8) ) ;
     if( ( Pere_ATiii(*A ) != NULL )) {
       if( ( *A == Fg_ATiii(Pere_ATiii(*A ) ) )) {
            comp_noeud ++;
         Aff_fg_ATiii(Pere_ATiii(*A ) , F ) ;
         }
       else
         {
         Aff_fd_ATiii(Pere_ATiii(*A ) , F ) ;
         _Px9 =  Fd_ATiii(Pere_ATiii(*A ) ) ;
         _Px10 =  Fg_ATiii(Pere_ATiii(*A ) ) ;
         Aff_struct3_Tiii(Info_ATiii(Pere_ATiii(*A ) )  , Max(Hauteur ( &_Px9) , Hauteur ( &_Px10) ) + 1 ) ;
         _Px11 =  Fg_ATiii(Pere_ATiii(*A ) ) ;
         _Px12 =  Fd_ATiii(Pere_ATiii(*A ) ) ;
         Aff_struct2_Tiii(Info_ATiii(Pere_ATiii(*A ) )  , Hauteur ( &_Px11) - Hauteur ( &_Px12) ) ;

       } ;
       }
     else
       {
       *R  =  F ;

     } ;
     Aff_pere_ATiii(F , Pere_ATiii(*A ) ) ;
     Aff_pere_ATiii(*A , F ) ;

    }
  void Rotation_g (Pointeur_ATiii *A , Pointeur_ATiii *R)
    {
      /** Variables locales **/
      Pointeur_ATiii F;
      Pointeur_ATiii _Px1;
      Pointeur_ATiii _Px2;
      Pointeur_ATiii _Px3;
      Pointeur_ATiii _Px4;
      Pointeur_ATiii _Px5;
      Pointeur_ATiii _Px6;
      Pointeur_ATiii _Px7;
      Pointeur_ATiii _Px8;
      Pointeur_ATiii _Px9;
      Pointeur_ATiii _Px10;
      Pointeur_ATiii _Px11;
      Pointeur_ATiii _Px12;

      /** Corps du module **/
      comp_rotation ++;
     F  =  Fd_ATiii(*A ) ;
     comp_noeud ++;
     Aff_fd_ATiii(*A , Fg_ATiii(F ) ) ;
     Aff_fg_ATiii(F , *A ) ;
     if( ( Fd_ATiii(*A ) != NULL )) {
       Aff_pere_ATiii(Fd_ATiii(*A ) , *A ) ;

     } ;
     _Px1 =  Fg_ATiii(*A ) ;
     _Px2 =  Fd_ATiii(*A ) ;
     Aff_struct3_Tiii(Info_ATiii(*A )  , Max(Hauteur ( &_Px1) , Hauteur ( &_Px2) ) + 1 ) ;
     _Px3 =  Fg_ATiii(*A ) ;
     _Px4 =  Fd_ATiii(*A ) ;
     Aff_struct2_Tiii(Info_ATiii(*A )  , Hauteur ( &_Px3) - Hauteur ( &_Px4) ) ;
     _Px5 =  Fg_ATiii(F ) ;
     _Px6 =  Fd_ATiii(F ) ;
     Aff_struct3_Tiii(Info_ATiii(F )  , Max(Hauteur ( &_Px5) , Hauteur ( &_Px6) ) + 1 ) ;
     _Px7 =  Fg_ATiii(F ) ;
     _Px8 =  Fd_ATiii(F ) ;
     Aff_struct2_Tiii(Info_ATiii(F )  , Hauteur ( &_Px7) - Hauteur ( &_Px8) ) ;
     if( ( Pere_ATiii(*A ) != NULL )) {
            comp_noeud ++;
       if( ( *A == Fg_ATiii(Pere_ATiii(*A ) ) )) {
         Aff_fg_ATiii(Pere_ATiii(*A ) , F ) ;
         }
       else
         {
         Aff_fd_ATiii(Pere_ATiii(*A ) , F ) ;
         _Px9 =  Fd_ATiii(Pere_ATiii(*A ) ) ;
         _Px10 =  Fg_ATiii(Pere_ATiii(*A ) ) ;
         Aff_struct3_Tiii(Info_ATiii(Pere_ATiii(*A ) )  , Max(Hauteur ( &_Px9) , Hauteur ( &_Px10) ) + 1 ) ;
         _Px11 =  Fg_ATiii(Pere_ATiii(*A ) ) ;
         _Px12 =  Fd_ATiii(Pere_ATiii(*A ) ) ;
         Aff_struct2_Tiii(Info_ATiii(Pere_ATiii(*A ) )  , Hauteur ( &_Px11) - Hauteur ( &_Px12) ) ;

       } ;
       }
     else
       {
       *R  =  F ;

     } ;
     Aff_pere_ATiii(F , Pere_ATiii(*A ) ) ;
     Aff_pere_ATiii(*A , F ) ;

    }
  void Rotation_droite (Pointeur_ATiii *A , Pointeur_ATiii *R)
    {
      /** Variables locales **/
      Pointeur_ATiii _Px1;
      Pointeur_ATiii _Px2;
      Pointeur_ATiii _Px3;

      /** Corps du module **/
     if( ( *A != NULL )) {
       _Px1 =  Fg_ATiii(Fg_ATiii(*A ) ) ;
       _Px2 =  Fd_ATiii(Fg_ATiii(*A ) ) ;
       if( ( Hauteur ( &_Px1) < Hauteur ( &_Px2) )) {
         _Px3 =  Fg_ATiii(*A ) ;
         comp_noeud ++;
         Rotation_gauche ( &_Px3, & *R ) ;

       } ;
       Rotation_d ( & *A , & *R ) ;

     } ;

    }
  void Rotation_gauche (Pointeur_ATiii *A , Pointeur_ATiii *R)
    {
      /** Variables locales **/
      Pointeur_ATiii _Px1;
      Pointeur_ATiii _Px2;
      Pointeur_ATiii _Px3;

      /** Corps du module **/
     if( ( *A != NULL )) {
       _Px1 =  Fd_ATiii(Fd_ATiii(*A ) ) ;
       _Px2 =  Fg_ATiii(Fd_ATiii(*A ) ) ;
       if( ( Hauteur ( &_Px1) < Hauteur ( &_Px2) )) {
         _Px3 =  Fd_ATiii(*A ) ;
         comp_noeud ++;
         Rotation_droite ( &_Px3, & *R ) ;

       } ;
       Rotation_g ( & *A , & *R ) ;

     } ;

    }
  void Transf_arb_avl (Pointeur_ATiii *A , Pointeur_ATiii *R)
    {
      /** Variables locales **/
      Pointeur_ATiii _Px1;
      Pointeur_ATiii _Px2;
      Pointeur_ATiii _Px3;
      Pointeur_ATiii _Px4;
      Pointeur_ATiii _Px5;
      Pointeur_ATiii _Px6;

      /** Corps du module **/
      comp_noeud ++;
     if( ( *A != NULL )) {
       _Px1 =  Fg_ATiii(*A ) ;
       Transf_arb_avl ( &_Px1, & *R ) ;
       _Px2 =  Fd_ATiii(*A ) ;
       Transf_arb_avl ( &_Px2, & *R ) ;
       _Px3 =  Fg_ATiii(*A ) ;
       _Px4 =  Fd_ATiii(*A ) ;
       Aff_struct3_Tiii(Info_ATiii(*A )  , Max(Hauteur ( &_Px3) , Hauteur ( &_Px4) ) + 1 ) ;
       _Px5 =  Fg_ATiii(*A ) ;
       _Px6 =  Fd_ATiii(*A ) ;
       Aff_struct2_Tiii(Info_ATiii(*A )  , Hauteur ( &_Px5) - Hauteur ( &_Px6) ) ;
       while( ( ( Struct2_Tiii(Info_ATiii(*A )  ) > 1 ) || ( Struct2_Tiii(Info_ATiii(*A )  ) < - 1 ) )) {
         if( ( Struct2_Tiii(Info_ATiii(*A )  ) > 1 )) {
           Rotation_droite ( & *A , & *R ) ;
           }
         else
           {
           Rotation_gauche ( & *A , & *R ) ;

         } ;

       } ;

     } ;

    }
  void Libererarb (Pointeur_ATiii *R)
    {
      /** Variables locales **/
      Pointeur_ATiii _Px1;
      Pointeur_ATiii _Px2;

      /** Corps du module **/
     if( ( *R != NULL )) {
       ;
       _Px1 =  Fd_ATiii(*R ) ;
       Libererarb ( &_Px1) ;
       _Px2 =  Fg_ATiii(*R ) ;
       Libererarb ( &_Px2) ;
       Liberernoeud_ATiii(*R ) ;
       *R  =  NULL ;

     } ;

    }

  int main(int argc, char *argv[])
    {
     FILE* fichier_comp = NULL;
     fichier_comp= fopen("les_compteur.txt","a+");
     R  =  NULL ;
     M  =  10500 ;
     N  =  100 ;
     for( I  =  1 ;I <=  N   ; ++I){
       Alloc_tab_W100000i(&Tab ) ;
       Aleatab ( & Tab , & M ) ;
       Creer_tab_avl ( & R , & Tab , & M ) ;
       printf ( " %s", " \nAVANT l''EQUILIBRAGE:\n" ) ;
       Postordre_avl ( & R ) ;
       printf ( " %s", "\n______________________________________________________________________\n" ) ;
       printf ( " %s", "\n APRES L''EQUILIBRAGE:\n" ) ;
       Transf_arb_avl ( & R , & R ) ;
       Postordre_avl ( & R ) ;
       printf ( " %s", "\n______________________________________________________________________\n" ) ;
       Libererarb ( & R ) ;
       Liber_tab_W100000i(Tab ) ;
       fprintf(fichier_comp," ***  les resultats pour l'iteration: %d   ***\n",I);
        fprintf(fichier_comp," _Nombre des rotations : %d\n",comp_rotation);
        fprintf(fichier_comp," _Nombre des noeuds visites : %d\n",comp_noeud);
        fprintf(fichier_comp,"-----------------------------------------------------------\n");
        comp_rotation =0;
        comp_noeud =0;
     } ;
      fclose(fichier_comp);

      system("PAUSE");
      return 0;
    }

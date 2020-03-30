SOIENT
	R un ARB de (entier,entier,entier);
            i ,n,m,x des entiers;
	tab un vecteur(12)dynamique;
	Hauteur : FONCTION(entier);
	Inser_AVL : ACTION;
	Postordre_AVL : ACTION;
	Creer_Tab_AVL : ACTION;
	Rotation_d : ACTION;
	Rotation_g : ACTION;
	Rotation_droite : ACTION;
	Rotation_gauche : ACTION;
	Transf_ARB_AVL  : ACTION;
	AleaTab: ACTION;
	LibererARB : ACTION;
DEBUT
	R:=NIL;
        m:=12;
	n:=10;
	POUR i:=1,n,1
                alloc_tab(tab);
		Appel AleaTab(tab,m);
		Appel Creer_Tab_AVL(R,tab,m);
                ECRIRE(' AVANT l''EQUILIBRAGE:');
		Appel Postordre_AVL(R);
		ECRIRE('_____________________________________________');
                ECRIRE(' APRES L''EQUILIBRAGE:');
		Appel Transf_ARB_AVL(R,R);
		Appel Postordre_AVL(R);
                ECRIRE('_____________________________________________');
		Appel LibererARB(R);
		liber_tab(tab);
	FPOUR;
FIN
		
ACTION AleaTab(t,taille)
SOIENT
    	t un vecteur(12)dynamique;taille un entier;
    	i un entier;
DEBUT
            POUR i:=1,taille,1
        	aff_element(t[i], aleanombre(1000));
    	FPOUR;
FIN

FONCTION Hauteur(A):entier
SOIT A un ARB de (entier,entier,entier);
DEBUT
	SI (A = NIL) Hauteur:= -1;
	SINON Hauteur :=struct(info(A),3);
	FSI;
FIN


ACTION Inser_AVL(R,val)
SOIENT
    R un ARB de (entier,entier,entier);
    val un entier;
    p,f des pointeurs vers ARB de (entier,entier,entier);
    arret un BOOLEEN;
    S un (entier,entier,entier);
DEBUT
    init_struct(S,[0,0,0]);	
    SI (R=NIL)
    creernoeud(R);
    aff_info(R,S);
    aff_struct(info(R),1,val);
    SINON
          p:=R;   arret:=faux;
          TQ (arret=faux)
          SI (struct(info(p),1)= val)
                arret:=vrai;
                SINON
                      SI (struct(info(p),1) > val)
                            SI (FG(p) = NIL)
                                  creernoeud(f);
                                  aff_info(f,S);
                                  aff_fg(p,f);
                                  aff_struct(info(FG(p)),1,val);
                                  aff_pere(FG(p),p);
                                  arret:=vrai;
                            SINON
                                  p:=FG(p);
                             FSI;
                      SINON
                             SI (FD(p) = NIL)
                                  creernoeud(f);
		          aff_info(f,S);
                                  aff_fd(p,f);
                                  aff_struct(info(FD(p)),1,val);
                                  aff_pere(FD(p),p);
                                  arret:= vrai;
                             SINON
                                  p:=FD(p);
                             FSI;
                      FSI;
                 FSI;
          FTQ;
     FSI;
FIN

ACTION Postordre_AVL ( R )
   SOIENT
       R UN ARB de (entier,entier,entier);
      
   DEBUT
       SI ( R <> NIL )
           APPEL Postordre_AVL ( FG ( R ) ) ;
           APPEL Postordre_AVL ( FD ( R ) ) ;
           ECRIRE ( struct ( info(R),1 ) ) ;
           ECRIRE ( '' ) ;
          
       FINSI ;
   FIN

ACTION Creer_Tab_AVL(R,tab,taille)
SOIENT
     R un ARB de (entier,entier,entier);
     taille,i des entiers;
     tab un vecteur(12)dynamique;
DEBUT
     POUR i:=1,taille,1
          Appel Inser_AVL(R,element(tab[i]));
     FPOUR;
FIN

ACTION Rotation_d(A,R)
SOIENT
	A,f des pointeurs vers ARB de (entier,entier,entier);
	R un ARB de (entier,entier,entier);
DEBUT
	f:=FG(A);
	aff_FG(A,FD(f));
	aff_FD(f,A);
	SI (FG(A)<>NIL)  aff_pere(FG(A),A);
	FSI;
	aff_struct(info(A),3,max(Hauteur(FG(A)) ,Hauteur(FD(A)))+ 1);
	aff_struct(info(A),2,Hauteur(FG(A)) - Hauteur(FD(A)));
	aff_struct(info(f),3,max(Hauteur(FD(f)),Hauteur(FG(f))) +1 );
	aff_struct (info(f),2,Hauteur(FG(f)) - Hauteur(FD(f)) );
	SI (PERE(A) <> NIL)
		SI (A= FG(PERE(A)))
			aff_fg(PERE(A),f);
		SINON  aff_fd(PERE(A),f);
		aff_struct(info(PERE(A)),3, max( Hauteur(FD(PERE(A))),Hauteur(FG(PERE(A))) ) + 1);
		aff_struct( info(PERE(A)),2,Hauteur(FG(PERE(A))) - Hauteur(FD(PERE(A))) );
		FSI;
	SINON R:=f;
	FSI;
	aff_pere(f,PERE(A));
	aff_pere(A,f);
FIN

ACTION Rotation_g(A,R)
SOIENT
	A,f des pointeurs vers ARB de (entier,entier,entier);
	R un ARB de (entier,entier,entier);
DEBUT
	f:=FD(A);
	aff_fd(A,FG(f));
	aff_fg(f,A);
	SI(FD(A)<>NIL)  aff_pere(FD(A),A);
	FSI;
	aff_struct(info(A),3,max(Hauteur(FG(A)),Hauteur(FD(A))) + 1);
	aff_struct(info(A),2,Hauteur(FG(A)) - Hauteur(FD(A)));
	aff_struct(info(f),3,max(Hauteur(FG(f)),Hauteur(FD(f))) + 1);
	aff_struct (info(f),2,Hauteur(FG(f)) - Hauteur(FD(f)));
	SI (PERE(A) <> NIL)
		SI (A= FG(PERE(A)))
			aff_fg(PERE(A),f);
		SINON  aff_fd(PERE(A),f);
		aff_struct(info(PERE(A)), 3,max( Hauteur(FD(PERE(A))),Hauteur(FG(PERE(A))) ) + 1);
		aff_struct(info( PERE(A)),2,Hauteur(FG(PERE(A))) - Hauteur(FD(PERE(A))) );
		FSI;
	SINON R:=f;
	FSI;
	aff_pere(f,PERE(A));
	aff_pere(A,f);
FIN

ACTION Rotation_droite(A,R)
SOIENT
	R un ARB de (entier,entier,entier);
	A un pointeur vers un  ARB de (entier,entier,entier);
DEBUT
	SI ( A<> NIL)
		SI (Hauteur(FG(FG(A))) < Hauteur(FD(FG(A))))  Appel Rotation_gauche(FG(A),R);
		FSI;
		Appel Rotation_d(A,R);
	FSI;
FIN

ACTION  Rotation_gauche(A,R)
SOIENT
	R un ARB de (entier,entier,entier);
	A un pointeur vers un  ARB de (entier,entier,entier);
DEBUT
	SI ( A<> NIL)
		SI (Hauteur(FD(FD(A))) < Hauteur(FG(FD(A)))) Appel Rotation_droite(FD(A),R);
		FSI;
		Appel Rotation_g(A,R);	
	FSI;
FIN


ACTION Transf_ARB_AVL(A,R)
SOIENT
	R un ARB de (entier,entier,entier);
	A un pointeur vers un  ARB de (entier,entier,entier);
DEBUT
	SI (A <> NIL)
		Appel Transf_ARB_AVL(FG(A),R);
		Appel Transf_ARB_AVL(FD(A),R);
		aff_struct(info(A),3,max(Hauteur(FG(A)) ,Hauteur(FD(A))) + 1);
		aff_struct(info(A),2,Hauteur(FG(A)) - Hauteur(FD(A)));
		TQ ((struct(info(A),2)> 1) ou ( struct(info(A),2)< -1))
			SI (struct(info(A),2) > 1)   Appel Rotation_droite(A,R);
			SINON Appel Rotation_gauche(A,R);
			FSI;
		FTQ;
	FSI;
FIN

ACTION LibererARB(R)
SOIT R un pointeur vers ARB de (entier,entier,entier);
DEBUT
	SI (R<>NIL);
		appel LibererARB(FD(R));
	            appel LibererARB(FG(R));
		Liberernoeud(R);
		R:=NIL;
	FSI;
FIN


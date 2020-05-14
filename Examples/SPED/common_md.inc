C$$$$$
C
C General common blocks 
C
C$$$$
      COMMON/KXIS1/NRA,NLA,NP,NAPL,NMA,NTA,KVC,MAXKB,NATOM
     &,KFLAG,NLR,KEND,npoly,im1, IXMAX,IYMAX,ILNMX, IAISLE
      COMMON/KXIS3/KB,LCHK,NCHK(NSMAX),KCHK,KTYPE(NPMAX),KT(100)
     &,KT2(100),ITR(NPMAX),MLIST(NPMAX),NLIST(NPMAX),IPOT,ILJ,KTMAX 
     &,NOA(NTYPES),LSTEP,nxmol,IDUM,ks1(npmax,2),ks2(npmax,2),
     & La(NPMAX),La1(NPMAX),La2(NPMAX),ilug(NPMAX),iluggage,itlug
      COMMON/C0/R0(NPMAX,3),R1(NPMAX,3),R2(NPMAX,3),R3(NPMAX,3)
     &,R4(NPMAX,3),xmtot,rsta(npmax),rb2(4,4),RR1(NPMAX),
     & ss1(npmax,2),ss2(npmax,2),dluggage, tlug,SCA,SCB, sigt1, epst1 
      COMMON/AXIS1/HEAD(20)
      COMMON/CNP/RNP(NPMAX,3)
      COMMON/C0L/R0L(NPMAX,3)
      COMMON/CDA/DAX(NPMAX),DAY(NPMAX),DAZ(NPMAX)
      COMMON/XIS3/RLL,CUBE(3),CUBE2(3),TOTE,ECONV,ENPR
      COMMON/XIS4/EPSI,SIGMA,XMASS(NTYPES)
      COMMON/XIS7/DELTA,TSTEP,EPAR1,EPAR2,HDEL(NSMAX),TTIME,TIME 
      COMMON/XIS1/PSEED,GSIG,BET,TR,TEM,WD,PI2,DNLA,
     &EN(NSMAX),pi,GL(3*NPMAX)
      COMMON/XIS2/F02,F12,F32,F42,F52,DELTSQ
      COMMON/XIS11/XKE(NLMAX),XKEA,TTCONV,PCONV
      COMMON/ETT/ETOT(NSMAX),eatom(npmax) 
      COMMON/CRAN/QBASE,QA1,QA2,QB1,QB2
      COMMON/NNREM/NR,IREM(NPMAX),KREM(NPMAX),NREM
      COMMON/PEN/PENET
      COMMON/NCOMP/newlist1(npmax),newlist2(npmax,8)
      COMMON/XIS12/PR0(NPMAX,3),QR0(NPMAX,3),pq1(NPMAX),React(1000,500),
     & reacty(1000,500),z1max1,z1min2,deldis1,deldis2 
      COMMON/KXIS12/nlotype,ndelst,nhs,nfindstr,ismax(1000),ismin(1000),
     & ipq2(1000)
      COMMON/ZKS/zx(500),nL
      COMMON/MINIM/ NMIN,IDMINN(10000)
      REAL*4 time0, time1, time2, time3, time4, time5, mmm, sss
      REAL ta(2), cbe(3) 
      COMMON/TIMING/ ta, time0, time1, time2, time3, time4, time5
 

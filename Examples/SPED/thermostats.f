      subroutine setgle
      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'

c
C
C Debye temperature converted to fs-1 X 2Pi
C
      WD=2230.0d0*(2.08365D-05)*2.0d0*PI

c
C LANGEVIN PARAMETERS
C


      TR=TEM/EPSI/ECONV
      BET=WD*PI*ECONV/6.0d0/DELTA
      GSIG=SQRT(2.0d0*TR*ECONV*BET)
      PI2=PI*2.0d0
      DNLA=3.0d0*DELTA*DELTA*FLOAT(NTA)

      do i=1,NP
        RR=RANNUM(i)
        RR1(i)=RR
      enddo
  
      return
      end 

      SUBROUTINE thermos
      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'
c
    
      IF(KFLAG.EQ.-1) CALL GLEQ
      IF(KFLAG.EQ.1) CALL BERE
      IF(KFLAG.EQ.2) CALL ZERO
      IF(KFLAG.EQ.3) CALL HOOV
      return
      end 


      SUBROUTINE GLEQ
C
C FRICTION AND RANDOM FORCE
C
      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'
c

      nlr = 3*NTA/2

      DO 20 I=1,NLR
           RR = RANNUM(I)
           IF(RR.LT.1.0D-06) GO TO 20
           PRE=SQRT(-2.0d0*LOG(RR))
           GL(I)=PRE*COS(PI2*RANNUM(I))*GSIG
           GL(I+NLR)=PRE*SIN(PI2*RANNUM(I))*GSIG
   20 CONTINUE
C
      DO 30 II=1,NTA
           I=NLIST(II)
           BM=BET*XMASS(KTYPE(I))
           SM=SQRT(XMASS(KTYPE(I)))
           DO 29 J=1,3
                rrzp = RNP(I,J)
                RNP(I,J)=RNP(I,J)-BM*R1(I,J)-SM*GL(II+(J-1)*NTA)
29         CONTINUE
30    CONTINUE
      RETURN
      END

C
      SUBROUTINE BERE
C
C USE BERENDSEN SCHEME
C
      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'
c
      XX=0.0d0
      DO 11 J=1,3
C
           DO 10 II=1,NTA
                I = NLIST(II)
                XX=XX+(R1(I,J)*R1(I,J))*XMASS(KTYPE(I))
   10      CONTINUE
C
   11 CONTINUE
c
      if(xx.lt.0.0d-7) then
            write(*,*) 'T=0, Reset Thermostat to other than 1'
            stop
      endif  
C
      IF(KFLAG.EQ.1) THEN
C
           SC=BET*(TR*DNLA/XX-1.0d0)
C
           DO 30 II=1,NTA
                I = NLIST(II)
                SM=XMASS(KTYPE(I))*SC
C
                DO 29 J=1,3
                     RNP(I,J)=RNP(I,J)+SM*R1(I,J)
29              CONTINUE
C
30         CONTINUE
C
      ELSE
C
           SC=SQRT(TR*6.0D0*DELTSQ*FLOAT(NTA)/XX)
           DO 32 II=1,NTA
                I = NLIST(II)
C
                DO 31 J=1,3
                     R1(I,J)=SC*R1(I,J)
31              CONTINUE
C
32         CONTINUE
C
      ENDIF
      RETURN
      END
C
      SUBROUTINE HOOV
C
C USE EVANS-HOOVER SCHEME
C
      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'
C
C this used for all atoms
c
      FF=0.0D0
      DF=0.0D0
      DO 2 J=1,3
           DO 1  I=1,NP
                FF=FF+RNP(I,J)*R1(I,J)
                DF=DF+R1(I,J)*R1(I,J)*XMASS(KTYPE(I))
1          CONTINUE
2     CONTINUE
C
      SC=FF/DF
C
      DO 4 J=1,3
C
           DO 3 I=1,NP
                RNP(I,J)=RNP(I,J)-SC*R1(I,J)*XMASS(KTYPE(I))
3          CONTINUE
C
4     CONTINUE
      RETURN
      END
C
      SUBROUTINE ZERO
C
C ZERO VELOCITIES
C
      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'
C
C note - this works on all atoms
c
       do i=1,np

      ss1(i,1)=100
      ss2(i,1)=100
      ss1(i,2)=-100
      ss2(i,2)=-100
      s1=0
      s2=0

       do j=1,2
      ks1(i,j)=0
      ks2(i,j)=0
       enddo
       enddo

      do i=1,NP
         do j=1,NP
            if((itr(i).eq.1).and.(itr(j).eq.1))then
           s1= R0(j,1)-R0(i,1)
           s2= R0(j,2)-R0(i,2)
           if((s1.eq.0).and.(s2.eq.0))goto 101

           if(abs(s1).gt.1.05*abs(s2))then
           if((s1.gt.0).and.(s1.lt.ss1(i,1)))then
              ss1(i,1)=s1
              ks1(i,1)=j
            elseif((s1.le.0).and.(s1.gt.ss1(i,2)))then
              ss1(i,2)=s1
              ks1(i,2)=j
           endif   

           endif   

           if(abs(s2).gt.1.05*abs(s1))then
           if((s2.gt.0).and.(s2.lt.ss2(i,1)))then
              ss2(i,1)=s2
              ks2(i,1)=j
            elseif((s2.le.0).and.(s2.gt.ss2(i,2)))then
              ss2(i,2)=s2
              ks2(i,2)=j
           endif   
           endif   

101         continue
           endif
          enddo
       enddo   
       
       do i=1,NP
          do j=1,2
          ss1(i,j)=abs(ss1(i,j))
          ss2(i,j)=abs(ss2(i,j))
          enddo
       enddo   

c
c      DO I=1,NP
c         R1(I,1)=R1(I,1)/DELTA
c         R1(I,2)=R1(I,2)/DELTA
c         R1(I,3)=0
c      ENDDO   

      
c      write(9,*) LSTEP,SCA
C ASSIGN INTENTION VELOCITIES TO PEOPLE
      DO I=1,NP
         RR=RANNUM(I)
c SC in 1 mile/hr
           SC= 10 + RR*7.6
c
              SC=SCA*SC

           SC1=0.7*SC
           SC2=1/SCB

c1120
        ILNMX=915
        IAISLE=8
        IYMAX=68
        IXMAX=945

         IF (ITR(I).EQ.1)THEN

c       IF(((KT2(KTYPE(I)).eq.14).and.(LSTEP.gt.12000)).or.
c     & ((KT2(KTYPE(I)).eq.15).and.(LSTEP.gt.24000)).or.
c     & (KT2(KTYPE(I)).eq.13))THEN


         If (abs(R0(I,2)).lT.IYMAX)then   
         If (abs(R0(I,1)).lT.IXMAX)then   


c out of seats
          IF(R0(I,1).LT.ILNMX)THEN  
             IF(R0(I,2).le.0)then
                R1(I,2)=SC*(1-1/(SC2*ss2(i,1)))-R1(I,2)
             ELSEIF(R0(I,2).GT.0)then
                R1(I,2)=-1*SC*(1-1/(SC2*ss2(i,2)))+R1(I,2)               
             ENDIF
           ENDIF
  
c  in hallway
          IF(R0(I,1).LT.ILNMX)THEN  
          If(abs(R0(i,2)).lt.IAISLE)then
             R1(I,1)= SC*(1-1/(SC2*ss1(i,1)))-R1(I,1)
          ENDIF
          ENDIF
c at gates
c
          IF((R0(I,1).GT.ILNMX).and.(R0(I,1).lt.IXMAX))THEN  
             IF((R0(I,2).LT.IYMAX).and.(R0(I,2).gt.-1*IYMAX))THEN             
            R1(I,2)= SC*(1-1/(SC2*ss2(i,1)))-R1(I,2)
              ENDIF   
          Endif    


         ENDIF 
         ENDIF 
         ENDIF 
c         ENDIF
      ENDDO  

      do i=1,NP
         R1(I,1)=R1(I,1)*DELTA
         R1(I,2)=R1(I,2)*DELTA
         R1(I,3)=0
      enddo   




      RETURN
      END

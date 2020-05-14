      subroutine setpc
      IMPLICIT REAL*8(A-H,O-Z)
C
      include 'common_files.inc'

C
C NORDSIECK PREDICTOR-CORRECTOR COEFFICIENTS
C
      F02=1.0d0/6.0d0
      F12=5.0d0/6.0d0
      F32=1.0d0/3.0d0
c
      return 
      end 
c 
      SUBROUTINE CPRED
      IMPLICIT REAL*8(A-H,O-Z)
C
      include 'common_files.inc'
      IF((KFLAG.NE.6).AND.(KFLAG.NE.8)) THEN
           IF(NMA.NE.0) CALL PRED
           TTIME=TTIME+DELTA
           time = time + delta
      ENDIF
      return
      end 

      SUBROUTINE ccorr
      IMPLICIT REAL*8(A-H,O-Z)
C
      include 'common_files.inc'
      IF((KFLAG.NE.6).AND.(KFLAG.NE.8)) THEN
              IF(NMA.NE.0) CALL CORR
      endif
      return
      end 

      SUBROUTINE PRED
      IMPLICIT REAL*8(A-H,O-Z)
C
      include 'common_files.inc'
C
C THIRD ORDER PREDICTOR
C
c      write(57,*)'inpred', NMA, LSTEP
      DO 31 J=1,3
           DO 30 II=1,NMA
                I = mlist(II)
                R0(I,J)=R0(I,J)+R1(I,J)+R2(I,J)+R3(I,J)
                R1(I,J)=R1(I,J) + 2.0d0*R2(I,J) + 3.0d0*R3(I,J)
                R2(I,J)=R2(I,J) + 3.0d0*R3(I,J)
                R0(I,J)=R0(I,J)-CUBE(J)*ANINT(R0(I,J)/CUBE(J))
c                write(57,120) ii, mlist(ii),R0(I,2), R1(I,2),R2(I,2)

   30      CONTINUE
   31 CONTINUE

cluggage stop
      if (iluggage.eq.1)then
      do i=1,NP
         if((LSTEP.gt.La1(i)).and.(LSTEP.lt.La2(i)))then
          do j=1,3
             R0(i,j)=QR0(i,j)
          enddo
         endif
      enddo   
      endif
c
 120  format(2i8,3f12.5)
      RETURN
      END
C
C*****
C
      SUBROUTINE CORR
      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'
C
      DIMENSION COM(3),ROP(1000,500),ROPy(1000,500)
      DIMENSION posza(100,100),velza(100,100),ua(100,100),duza(100,100)
c
C  THIRD ORDER CORRECTOR
C

cccccccccccc
      DE=DELTSQ/ECONV
      DO 1 J=1,3
      DO 2 II=1,NMA
           I = mlist(II)
           XXM=XMASS(KTYPE(I))
           RI=R2(I,J) - DE*RNP(I,J)/XXM
           RI1=R2(I,1) - DE*RNP(I,1)/XXM
           RI2=R2(I,2) - DE*RNP(I,2)/XXM
           R0(I,J)=R0(I,J) - RI*F02
           R1(I,J)=R1(I,J) - RI*F12
           R2(I,J)=R2(I,J) - RI
           R3(I,J)=R3(I,J) - RI*F32
C
           R0(I,J)=R0(I,J)-CUBE(J)*ANINT(R0(I,J)/CUBE(J))


   2  CONTINUE
   1  CONTINUE

 120  format(2i8,5f16.3)

c luggage stop
      if (iluggage.eq.1)then
      do i=1,NP
         if((LSTEP.gt.La1(i)).and.(LSTEP.lt.La2(i)))then
          do j=1,3
             R0(i,j)=QR0(i,j)
          enddo
         endif
      enddo   
      endif      
c
      do i=1,NP
      IF((R0(i,2).gt.IYMAX).and.(R0(i,2).lt.(IYMAX+20)))then
         R0(i,2)=R0(i,2)+40
      endif   
c

      enddo
C
C UPDATE NEIGHBOR LIST?
C
      RSQCRT=(0.5d0*RLL)**2
      DO 4 I=1,NP
      RSQ=0.0D0
      DO 3 J=1,3
           R=R0(I,J)-R0L(I,J)
           R = R - CUBE(J)*ANINT(R/CUBE(J))
           RSQ=RSQ+R*R
C
3     CONTINUE
           IF(RSQ.GT.RSQCRT) GO TO 5
4     CONTINUE
      LCHK=2
      GO TO 8
C

5     CONTINUE

C
C UPDATE NEIGHBOR LIST
C
      DO 7 J=1,3
           DO 6 I=1,NP
                R0L(I,J)=R0(I,J)
6          CONTINUE
7     CONTINUE
C

      KCHK=KCHK+1
C      NCHK(KCHK)=KB
      LCHK=1
C
8     CONTINUE
C
ccccccccccccccccc
c Fix if out of plane
c      DO I=1,NP
c        IF(abs(R0(I,2)).gt.105)then 
c            itr(I)=3
c         endif
c      enddo   
cccccccccccccccc

C
 100  format(2i9,5f16.9)
      RETURN
      END


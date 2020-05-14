      subroutine setin

      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'

      DATA KT/2,4*0,1,6*0,3,4,5,6,7,14*0,4,68*0/
      DATA KT2/6,1,13,14,15,16,17,93*0/
c
      do i=1,ntypes
          xmass(i) = 0.0d0
          noa(i) = 0
          do j=1,ntypes
               sig(i,j) = 0.0d0
               eps(i,j) = 0.0d0
          enddo
      enddo
      xmass(1) = 12.0d0
      xmass(2) = 1.0d0
      xmass(4) =150.0d0
      xmass(5)= 150.0d0
      xmass(6)= 150.0d0
      xmass(7)= 150.0d0
      xmass(3) =150.0d0
       PI=ACOS(-1.D0)
      BOLZ=1.380662d0
      EPSI=11604.5D0
      AVO=6.02205
c      ECONV=(1.0D0/(AVO*BOLZ*EPSI))*1.0D+07
      ECONV=1
      do i=1,NP
      La(i)=0
      La1(i)=0
      La2(i)=0
      enddo
c

      return 
      end 

      subroutine setpp

      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'


      if(ilj.ne.0) call ljparam

      return
      end 

      subroutine setmd 
      IMPLICIT REAL*8(A-H,O-Z)
c
      include 'common_files.inc'

            IF(NMA.ne.0) THEN
                  ENPR=EPSI/FLOAT(NMA)
            ELSE
                 ENPR=0.0D0
            ENDIF
C
            xkea = 0.0d0
            time = 0.0d0
            lchk = 1

            return 
            end 

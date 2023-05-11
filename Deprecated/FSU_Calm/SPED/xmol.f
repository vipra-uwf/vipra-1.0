      SUBROUTINE XMOL
      IMPLICIT REAL*8(A-H,O-Z)
      include 'common_files.inc'
        integer krank, ksize, kerr
c        call MPI_COMM_SIZE(MPI_COMM_WORLD, ksize, kerr)
c        call MPI_COMM_RANK(MPI_COMM_WORLD, krank, kerr)      


C
c      WRITE(1,1800) HEAD
      WRITE(1,'(i5)')NP
      WRITE(1,*)' ', lstep

ccccccccccccccccc
c color walls blue
      DO I=1,NP
        IF(I.gt.288) then 
            itr(I)=3
         endif
      enddo   
cccccccccccccccc

C
      DO 11 I=1,NP
         IF(ITR(I).EQ.1)THEN
      WRITE(1,360)R0(I,1),R0(I,2), R0(I,3)
         ELSEIF(ITR(I).eq.2)then
      WRITE(1,370)(R0(I,N),N=1,3)
      else
      WRITE(1,380)(R0(I,N),N=1,3)
        ENDIF
11    CONTINUE

      

C
      call flush(1)

  100 FORMAT(4I6)
  300 FORMAT(3E20.11)
  350 FORMAT(2I5,3E20.11)
  360 FORMAT('C',3f12.3)
  370 FORMAT('U',3f12.3)
  380 FORMAT('N',3f12.3)

 1800 FORMAT(20A2)
      return
      end

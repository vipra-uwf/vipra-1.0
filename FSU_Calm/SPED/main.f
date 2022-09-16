C##############################################################C
C                                                              C
C                                                              C
C  THESE PROGRAMS PERFORM MOLECULAR DYNAMICS SIMULATIONS WITH  C
C  BOND-ORDER POTENTIALS FOR HYDROCARBON, SILICON AND          C
C  GERMANIUM; TIGHT BINDING FOR CARBON; AND LENNARD-JONES      C
C  WITH INPUTTED PARAMETERS. THE LATTER POTENTIALS ARE         C 
C  TRUNCATED AT SMALL DISTANCES FOR C-C, H-H, AND C-H PAIRS    C 
C                                                              C
C   Units: mass = AMU's, length = Angstroms, time = fs         C
C          energy = eV's                                       C
C                                                              C
C   DOCUMENTATION CAN BE FOUND IN:                             C
C      /MD/Documentation                                       C 
C                                                              C
C##############################################################C
comment
      SUBROUTINE vipra(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)  
      IMPLICIT REAL*8(A-H,O-Z)
      integer Arg1, Arg2
      COMMON/mpi/ rank, size
c       Arg3, Arg4, Arg5, Arg6, Arg7
      include 'common_files.inc'
      CHARACTER*100 MNO, MESSAGE
      integer rank, size, ierror, tag, status(MPI_STATUS_SIZE)

      time1 = 0
      time2 = 0
      time3 = 0
      time4 = 0
      time5 = 0
c        call MPI_INIT(ierror)
c        call MPI_COMM_SIZE(MPI_COMM_WORLD, size, ierror)
c        call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierror)      
c 
c open input/output files 
c      include 'open.inc' 
      EVERYBODY_OUT=0
      NON_PROG=0

       rank = Arg1
       size = Arg2
       SCB = Arg3
       sigt1= Arg4
       epst1 = Arg5
       SCA = Arg6
       tlug = Arg7
        write(MESSAGE, *)rank
        MNO =adjustl(trim(MESSAGE))
        open (unit=11, file='coord.d', status='UNKNOWN')
c        open (unit=1, file='xmol.xyz', status='UNKNOWN')
c        open (unit=11, file='coord.d_'//MNO, status='UNKNOWN')
        open (unit=1, file='xmol.xyz_'//MNO, status='UNKNOWN')
        open(9,file='output.d_'//MNO,status='unknown')
c        open(13,file='input.d_'//MNO,status='unknown')
c uncomment above line and comment below for multiple input.d files
        open(13,file='input.d',status='old') 
        open(19,file='luggage.d',status='old')
    
        

c 
c************************* 
c set up and input data  * 
c*************************

c initialize 
      call setin 
C read input data 
c      call setpp
      call read_data 
C setup potential parameters  
      call setpp 
c setup predictor-corrector coefficients
      call setpc 
C setup Langevin parameters  
      call setgle 
C initialize random number generator 
      call setran 
c write out data headers 
      call write_data1 
C
c********************
c begin calculation *
c********************

c**********************
C Dynamic Simulation  *
c**********************
            call setmd 
C%%%
            call xmol
            DO LSTEP=1,KVC

c predictor
                 call cpred 
c calculate energy and forces
                   
                 CALL MODEL 

cs inorder to vary temperature              
c                 call setgle
c apply thermostats 
                 call thermos 
c corrector 
                 call ccorr

                 call flush(98) 
c write out position file to be post converted to xmol format
                 if(mod(LSTEP,nxmol).eq.0) call xmol
                 if(mod(LSTEP,maxkb).eq.0) then
c generate and write data 
                 call write_data2 
                 
                 if(EVERYBODY_OUT.eq.1) then
                     print *, rank, size, SCB
                     include 'close.inc'
                      return
                   endif
                 if(NON_PROG.eq.1) then
                     print *, rank, size
                     include 'close.inc'
                      return
                   endif
                 endif 


           ENDDO 
c
C UNCOMMENT  write data3 to
C WRITE OUT POSITIONS FOR RESTART
C
C *****IMPORTANT***********************
C                                     *
C !!! INPUT FILE IS WRITTEN OVER !!!  *
C                                     * 
C**************************************
C
c      call write_data3 
c      if(rank.eq.20) then 
c       print *, rank, size, SCB, sigt1, epst1, SCA, tlug
c      endif
c      print *, time2, time4, time2/KVC, time4/KVC, time5, time5/KVC
      
      include 'close.inc'
c       call MPI_FINALIZE(ierror)
c      STOP
       RETURN
      END
C
C add included subroutines
C
      include 'subroutines.inc' 

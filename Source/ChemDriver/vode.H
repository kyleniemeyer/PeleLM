      DOUBLE PRECISION YJ_SAVE(80)
      LOGICAL FIRST
      COMMON /VHACK/ YJ_SAVE, FIRST
      SAVE   /VHACK/

      DOUBLE PRECISION ACNRM, CCMXJ, CONP, CRATE, DRC, EL(13), &
          ETA, ETAMAX, H, HMIN, HMXI, HNEW, HSCAL, PRL1, &
          RC, RL1, TAU(13), TQ(5), TN, UROUND
      INTEGER ICF, INIT, IPUP, JCUR, JSTART, JSV, KFLAG, KUTH, &
             L, LMAX, LYH, LEWT, LACOR, LSAVF, LWM, LIWM, &
             LOCJS, MAXORD, METH, MITER, MSBJ, MXHNIL, MXSTEP, &
             N, NEWH, NEWQ, NHNIL, NQ, NQNYH, NQWAIT, NSLJ, &
             NSLP, NYH
      COMMON /DVOD01/ ACNRM, CCMXJ, CONP, CRATE, DRC, EL, &
                     ETA, ETAMAX, H, HMIN, HMXI, HNEW, HSCAL, PRL1, &
                     RC, RL1, TAU, TQ, TN, UROUND, &
                     ICF, INIT, IPUP, JCUR, JSTART, JSV, KFLAG, KUTH, &
                     L, LMAX, LYH, LEWT, LACOR, LSAVF, LWM, LIWM, &
                     LOCJS, MAXORD, METH, MITER, MSBJ, MXHNIL, MXSTEP, &
                     N, NEWH, NEWQ, NHNIL, NQ, NQNYH, NQWAIT, NSLJ, &
                     NSLP, NYH

      DOUBLE PRECISION HU
      INTEGER NCFN, NETF, NFE, NJE, NLU, NNI, NQU, NST
      COMMON /DVOD02/ HU, NCFN, NETF, NFE, NJE, NLU, NNI, NQU, NST
      SAVE /DVOD01/, /DVOD02/

!$omp threadprivate(/VHACK/,/DVOD01/,/DVOD02/)

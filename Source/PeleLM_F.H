#ifndef _PeleLM_F_H_
#define _PeleLM_F_H_ 

#ifndef BL_LANG_FORT

#include <AMReX_ArrayLim.H>

#ifdef __cplusplus
extern "C" {
#endif

  void active_control(const amrex::Real* fuelmass,
                          const amrex::Real* time,
                          const amrex::Real* crsedt, 
                          const int*  myproc,
                          const int*  step,
                          const int*  restart,
                          const int*  usetemp);

  void set_scal_numb(const int* Density,
                          const int* Temp,
                          const int* Trac,
                          const int* RhoH,
                          const int* FirstSpec,
                          const int* LastSpec);
    
  void get_pamb(amrex::Real* pamb);

  void get_closed_chamber(int* closed_chamber);

  void get_dpdt(amrex::Real* dpdt_factor);

  void compute_rho_dgrad_hdot_grad_Y(const amrex::Real* dx,
                                      const int* lo, const int* hi,
                                      ARLIM_P(speclo),ARLIM_P(spechi), const amrex::Real* specdat,
                                      ARLIM_P(hlo),ARLIM_P(hhi), const amrex::Real* hdat,
                                      ARLIM_P(betaxlo),ARLIM_P(betaxhi), const amrex::Real* betax,
                                      ARLIM_P(betaylo),ARLIM_P(betayhi), const amrex::Real* betay,
#if (BL_SPACEDIM == 3) 
                                      ARLIM_P(betazlo),ARLIM_P(betazhi), const amrex::Real* betaz,
#endif            
                                      ARLIM_P(ddrhslo),ARLIM_P(ddrhshi), amrex::Real* ddrhsdat);

  void divu_fill (amrex::Real* data, ARLIM_P(data_lo), ARLIM_P(data_hi),
                      const int* dom_lo, const int* dom_hi,
                      const amrex::Real* dx, const amrex::Real* grd_lo,
                      const amrex::Real* time, const int* bc);

  void dsdt_fill (amrex::Real* data, ARLIM_P(data_lo), ARLIM_P(data_hi),
                      const int* dom_lo, const int* dom_hi,
                      const amrex::Real* dx, const amrex::Real* grd_lo,
                      const amrex::Real* time, const int* bc);

  void dqrad_fill (amrex::Real* data, ARLIM_P(data_lo), ARLIM_P(data_hi),
                       const int* dom_lo, const int* dom_hi,
                       const amrex::Real* dx, const amrex::Real* grd_lo,
                       const amrex::Real* time, const int* bc);

  void ydot_fill (amrex::Real* data, ARLIM_P(data_lo), ARLIM_P(data_hi),
                      const int* dom_lo, const int* dom_hi,
                      const amrex::Real* dx, const amrex::Real* grd_lo,
                      const amrex::Real* time, const int* bc);

  void rhoYdot_fill (amrex::Real* data, ARLIM_P(data_lo), ARLIM_P(data_hi),
                         const int* dom_lo, const int* dom_hi,
                         const amrex::Real* dx, const amrex::Real* grd_lo,
                         const amrex::Real* time, const int* bc);

  void est_divu_dt(const int& flag,  const amrex::Real* divu_dt_factor,
                        const amrex::Real* dx, 
                        const amrex::Real* sdat,ARLIM_P(slo),ARLIM_P(shi),
                        const amrex::Real* dsdtdat,ARLIM_P(dslo),ARLIM_P(dshi),
                        const amrex::Real* rhodat,ARLIM_P(rholo),ARLIM_P(rhohi),
                        const amrex::Real* vel,ARLIM_P(ulo),ARLIM_P(uhi),
                        const amrex::Real* volume, ARLIM_P (v_lo), ARLIM_P (v_hi), 
                        const amrex::Real* areax,
                        ARLIM_P(areax_lo),ARLIM_P(areax_hi),
                        const amrex::Real* areay,
                        ARLIM_P(areay_lo),ARLIM_P(areay_hi),
#if (BL_SPACEDIM == 3) 
                        const amrex::Real* areaz,
                        ARLIM_P(areaz_lo),ARLIM_P(areaz_hi),
#endif            
                        const int* lo,const int* hi,
                        amrex::Real* dt, const amrex::Real* min_rho_divu_ceiling);

  void check_divu_dt(const int& flag, const amrex::Real* divu_dt_factor,
                          const amrex::Real* dx, 
                          const amrex::Real* sdat, ARLIM_P(slo), ARLIM_P(shi),
                          const amrex::Real* dsdtdat,
                          const amrex::Real* rhodat,ARLIM_P(rholo),ARLIM_P(rhohi),
                          const amrex::Real* vel,ARLIM_P(ulo),ARLIM_P(uhi),
                          const amrex::Real* volume, ARLIM_P (v_lo), ARLIM_P (v_hi), 
                          const amrex::Real* areax,
                          ARLIM_P(areax_lo),ARLIM_P(areax_hi),
                          const amrex::Real* areay,
                          ARLIM_P(areay_lo),ARLIM_P(areay_hi),
#if (BL_SPACEDIM == 3) 
                          const amrex::Real* areaz,
                          ARLIM_P(areaz_lo),ARLIM_P(areaz_hi),
#endif            
                          const int* lo,const int* hi,
                          const amrex::Real* dt, const amrex::Real* min_rho_divu_ceiling);

  
  void set_ht_visc_common(const int* muIsVar,     const amrex::Real* muVal,
                               const int* lambdaIsVar, const amrex::Real* lambdaVal,
                               const int* rhoDIsVar,   const amrex::Real* rhoDVal,
                               const amrex::Real* Pr, const amrex::Real* Sc, const int* unityLe);

  void init_typcals_common();
      
  void vel_visc(const int* lo, const int* hi,
                    ARLIM_P(tlo), ARLIM_P(thi), const amrex::Real* tempdat,
                    ARLIM_P(slo), ARLIM_P(shi), const amrex::Real* specdat,
                    ARLIM_P(blo), ARLIM_P(bhi), amrex::Real* betadat);

  void spec_temp_visc(const int* lo, const int* hi,
                         ARLIM_P(tlo), ARLIM_P(thi), const amrex::Real* tempdat,
                         ARLIM_P(slo), ARLIM_P(shi), const amrex::Real* specdat,
                         ARLIM_P(blo), ARLIM_P(bhi), amrex::Real* betadat,
                         const int* nCompD, const amrex::Real* P1ATM_MKS,
                         const int* do_temp, const int* do_VelVisc, 
                         const amrex::Real* Pamb_in);

  void fab_minmax (const int* lo, const int* hi,
                      amrex::Real* fabdat, ARLIM_P(flo), ARLIM_P(fhi),
                      const amrex::Real* min, const amrex::Real* max, const int* nc);

  void repair_flux(const int* lo,  const int* hi,
                        const int* dlo, const int* dhi,
                        amrex::Real* flux,    ARLIM_P(flo),  ARLIM_P(fhi),
                        const amrex::Real* RY,ARLIM_P(RYlo), ARLIM_P(RYhi),
                        const int* dir, const int* bc);

  void enth_diff_terms(const int* lo, const int* hi, 
                            const int* dlo, const int* dhi, const amrex::Real* dx,
                            const int* lo_x, const int* hi_x,
                            const int* dlo_x, const int* dhi_x,
                            const int* lo_y, const int* hi_y,
                            const int* dlo_y, const int* dhi_y,
#if BL_SPACEDIM == 3
                            const int* lo_z, const int* hi_z,
                            const int* dlo_z, const int* dhi_z,
#endif
                            const amrex::Real* T, ARLIM_P(Tlo),  ARLIM_P(Thi),
                            const amrex::Real* RhoY, ARLIM_P(rYlo),  ARLIM_P(rYhi),

                            const amrex::Real* rDx,ARLIM_P(rDxlo),ARLIM_P(rDxhi),
                            const amrex::Real* Fix,ARLIM_P(Fixlo),ARLIM_P(Fixhi),
                            const amrex::Real* ax, ARLIM_P(axlo), ARLIM_P(axhi),

                            const amrex::Real* rDy,ARLIM_P(rDylo),ARLIM_P(rDyhi),
                            const amrex::Real* Fiy,ARLIM_P(Fiylo),ARLIM_P(Fiyhi),
                            const amrex::Real* ay, ARLIM_P(aylo), ARLIM_P(ayhi),
#if BL_SPACEDIM == 3
                            const amrex::Real* rDz,ARLIM_P(rDzlo),ARLIM_P(rDzhi),
                            const amrex::Real* Fiz,ARLIM_P(Fizlo),ARLIM_P(Fizhi),
                            const amrex::Real* az, ARLIM_P(azlo), ARLIM_P(azhi),
#endif
                            amrex::Real* fh,      ARLIM_P(fhlo), ARLIM_P(fhhi),
                            const int* Tbc);

  void incrwext_flx_div (const int* lo, const int* hi,
                           const amrex::Real* xflux, ARLIM_P(fxlo),  ARLIM_P(fxhi),
                           const amrex::Real* yflux, ARLIM_P(fylo),  ARLIM_P(fyhi),
#if BL_SPACEDIM == 3
                           const amrex::Real* zflux, ARLIM_P(fzlo),  ARLIM_P(fzhi),
#endif
                           const amrex::Real* sto,     ARLIM_P(stolo),    ARLIM_P(stohi),
                           amrex::Real*       stn,     ARLIM_P(stnlo),    ARLIM_P(stnhi),
                           const amrex::Real* vol,     ARLIM_P(vollo),    ARLIM_P(volhi),
                           const int* nc, const amrex::Real* dt);

  void flux_div(const int* lo, const int* hi,
                    const amrex::Real* updat, ARLIM_P(uplo), ARLIM_P(uphi),
                    const amrex::Real* xflux, ARLIM_P(fxlo), ARLIM_P(fxhi),
                    const amrex::Real* yflux, ARLIM_P(fylo), ARLIM_P(fyhi),
#if BL_SPACEDIM == 3
                    const amrex::Real* zflux, ARLIM_P(fzlo), ARLIM_P(fzhi),
#endif
                    const amrex::Real* vol,   ARLIM_P(vlo),  ARLIM_P(vhi),
                    const int* nc, const amrex::Real* scale);

  void calc_divu_fortran(const int* lo,  const int* hi,
                     amrex::Real* divu,         ARLIM_P(dulo),    ARLIM_P(duhi),
                     const amrex::Real* rYdot,  ARLIM_P(rYdotlo), ARLIM_P(rYdothi),
                     const amrex::Real* vtY,    ARLIM_P(vtYlo),   ARLIM_P(vtYhi),
                     const amrex::Real* vtT,    ARLIM_P(vtTlo),   ARLIM_P(vtThi),
                     const amrex::Real* rhoY,   ARLIM_P(rYlo),    ARLIM_P(rYhi),
                     const amrex::Real* T,      ARLIM_P(Tlo),     ARLIM_P(Thi));

  void calc_gamma_pinv(const int* lo,  const int* hi,
                          amrex::Real* theta,        ARLIM_P(thlo),    ARLIM_P(thhi),
                          const amrex::Real* rhoY,   ARLIM_P(rYlo),    ARLIM_P(rYhi),
                          const amrex::Real* T,      ARLIM_P(Tlo),     ARLIM_P(Thi),
                          const amrex::Real* Pamb_in);
    
  void floor_spec(const int* lo,  const int* hi,
                      const amrex::Real* spec,   ARLIM_P(speclo),    ARLIM_P(spechi));

  void set_common (const amrex::Real* time, const int* iteration);

  void compute_ugradp (const amrex::Real* p, ARLIM_P(p_lo),  ARLIM_P(p_hi),
                           const amrex::Real* ugradp, ARLIM_P(up_lo),  ARLIM_P(up_hi),
                           const amrex::Real* umac, ARLIM_P(umac_lo),  ARLIM_P(umac_hi),
                           const amrex::Real* vmac, ARLIM_P(vmac_lo),  ARLIM_P(vmac_hi),
#if BL_SPACEDIM == 3
                           const amrex::Real* wmac, ARLIM_P(wmac_lo),  ARLIM_P(wmac_hi),
#endif
                           const int* lo, const int* hi, const amrex::Real* dx);

  void htdd_relax(const int* lo, const int* hi,
                      amrex::Real* s, ARLIM_P(slo),  ARLIM_P(shi),
                      const int& sCompY, const int& sCompT,
                      const int& sCompH, const int& sCompR,
                      const amrex::Real* L, ARLIM_P(Llo),  ARLIM_P(Lhi),
                      const amrex::Real* a, ARLIM_P(alo),  ARLIM_P(ahi),
                      const amrex::Real* r, ARLIM_P(rlo),  ARLIM_P(rhi),
                      const amrex::Real& thetaDt, const amrex::Real* fac, amrex::Real* maxRes, amrex::Real* maxCor,
                      const int& for_T0_H1, const int& res_only, const amrex::Real& mult);

  void get_typical_vals(amrex::Real* vals, const int* nVals);

  void set_typical_vals(const amrex::Real* vals, const int* nVals);

  int conservative_T_floor(const int* lo, const int* hi,
                                amrex::Real* fabdat, ARLIM_P(flo), ARLIM_P(fhi),
                                const amrex::Real* min_T_fine, const int* Tcomp, const int* Rcomp,
                                const int* first_comp, const int* last_spec, const int* RhoH,
                                const int* ratio, amrex::Real* tmp, const int* nt);
    
  void part_cnt_err(int* tag, ARLIM_P(tlo), ARLIM_P(thi),
                         const int* tagval, const int* clearval,
                         amrex::Real* data, ARLIM_P(data_lo), ARLIM_P(data_hi),
                         const int* lo, const int* hi, const int* nvar,
                         const int* domain_lo, const int* domain_hi,
                         const amrex::Real* dx, const amrex::Real* xlo,
                         const amrex::Real* prob_lo, const amrex::Real* time,
                         const int* level);

  void recomp_update(const int* lo, const int* hi,
                          const amrex::Real* updat, ARLIM_P(uplo), ARLIM_P(uphi),
                          const amrex::Real* xflux, ARLIM_P(fxlo), ARLIM_P(fxhi),
                          const amrex::Real* yflux, ARLIM_P(fylo), ARLIM_P(fyhi),
#if BL_SPACEDIM == 3
                          const amrex::Real* zflux, ARLIM_P(fzlo), ARLIM_P(fzhi),
#endif
                          const amrex::Real* vol,   ARLIM_P(vlo),  ARLIM_P(vhi),
                          const int* nc);

  void mcurve(const int* lo, const int* hi,
                   const amrex::Real* T, ARLIM_P(Tlo),  ARLIM_P(Thi),
                   amrex::Real*       K, ARLIM_P(Klo),  ARLIM_P(Khi),
                   amrex::Real*      nW, ARLIM_P(nwlo), ARLIM_P(nwhi),
                   const amrex::Real* delta);

  void smooth(const int* lo, const int* hi,
                   amrex::Real*       i, ARLIM_P(ilo), ARLIM_P(ihi),
                   const amrex::Real* o, ARLIM_P(olo), ARLIM_P(ohi));

  void grad_wbar(const int* lo, const int* hi,
                     const amrex::Real* Wbar, ARLIM_P(Wlo),    ARLIM_P(Whi),
                     const amrex::Real* rDe,  ARLIM_P(rDelo),  ARLIM_P(rDehi),
                     amrex::Real* flx,  ARLIM_P(flxlo),  ARLIM_P(flxhi),
                     const amrex::Real* a,    ARLIM_P(alo),    ARLIM_P(ahi),
                     const amrex::Real* delta, const int* dir,
                     const amrex::Real* mult, const amrex::Real* inc);
    
#ifdef __cplusplus
}
#endif
#endif

#endif /*_PeleLM_F_H_*/

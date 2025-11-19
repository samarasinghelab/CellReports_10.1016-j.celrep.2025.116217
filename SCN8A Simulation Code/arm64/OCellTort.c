/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__Ocellchann
#define _nrn_initial _nrn_initial__Ocellchann
#define nrn_cur _nrn_cur__Ocellchann
#define _nrn_current _nrn_current__Ocellchann
#define nrn_jacob _nrn_jacob__Ocellchann
#define nrn_state _nrn_state__Ocellchann
#define _net_receive _net_receive__Ocellchann 
#define rates rates__Ocellchann 
#define states states__Ocellchann 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define drive _p[0]
#define drive_columnindex 0
#define drivenoise _p[1]
#define drivenoise_columnindex 1
#define celldrive _p[2]
#define celldrive_columnindex 2
#define celldrivenoise _p[3]
#define celldrivenoise_columnindex 3
#define ina _p[4]
#define ina_columnindex 4
#define inap _p[5]
#define inap_columnindex 5
#define ik _p[6]
#define ik_columnindex 6
#define il _p[7]
#define il_columnindex 7
#define ia _p[8]
#define ia_columnindex 8
#define ih _p[9]
#define ih_columnindex 9
#define m _p[10]
#define m_columnindex 10
#define h _p[11]
#define h_columnindex 11
#define n _p[12]
#define n_columnindex 12
#define a _p[13]
#define a_columnindex 13
#define b _p[14]
#define b_columnindex 14
#define r _p[15]
#define r_columnindex 15
#define mp _p[16]
#define mp_columnindex 16
#define Dm _p[17]
#define Dm_columnindex 17
#define Dh _p[18]
#define Dh_columnindex 18
#define Dn _p[19]
#define Dn_columnindex 19
#define Da _p[20]
#define Da_columnindex 20
#define Db _p[21]
#define Db_columnindex 21
#define Dr _p[22]
#define Dr_columnindex 22
#define Dmp _p[23]
#define Dmp_columnindex 23
#define minf _p[24]
#define minf_columnindex 24
#define mtau _p[25]
#define mtau_columnindex 25
#define hinf _p[26]
#define hinf_columnindex 26
#define htau _p[27]
#define htau_columnindex 27
#define ninf _p[28]
#define ninf_columnindex 28
#define ntau _p[29]
#define ntau_columnindex 29
#define ainf _p[30]
#define ainf_columnindex 30
#define atau _p[31]
#define atau_columnindex 31
#define binf _p[32]
#define binf_columnindex 32
#define btau _p[33]
#define btau_columnindex 33
#define rinf _p[34]
#define rinf_columnindex 34
#define rtau _p[35]
#define rtau_columnindex 35
#define _g _p[36]
#define _g_columnindex 36
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_Ocellchann", _hoc_setdata,
 "rates_Ocellchann", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
#define el el_Ocellchann
 double el = -70;
#define eh eh_Ocellchann
 double eh = -32.9;
#define ea ea_Ocellchann
 double ea = -90;
#define ek ek_Ocellchann
 double ek = -100;
#define ena ena_Ocellchann
 double ena = 60;
#define gl gl_Ocellchann
 double gl = 5e-05;
#define gh gh_Ocellchann
 double gh = 0.012;
#define ga ga_Ocellchann
 double ga = 0.016;
#define gk gk_Ocellchann
 double gk = 0.023;
#define gnap gnap_Ocellchann
 double gnap = 5e-07;
#define gna gna_Ocellchann
 double gna = 0.03;
#define mtaup mtaup_Ocellchann
 double mtaup = 0;
#define minfp minfp_Ocellchann
 double minfp = 0;
#define v50 v50_Ocellchann
 double v50 = -84;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gna_Ocellchann", "mho/cm2",
 "gnap_Ocellchann", "mho/cm2",
 "ena_Ocellchann", "mV",
 "gk_Ocellchann", "mho/cm2",
 "ek_Ocellchann", "mV",
 "ga_Ocellchann", "mho/cm2",
 "ea_Ocellchann", "mV",
 "gh_Ocellchann", "mho/cm2",
 "eh_Ocellchann", "mV",
 "v50_Ocellchann", "mV",
 "gl_Ocellchann", "mho/cm2",
 "el_Ocellchann", "mV",
 "drive_Ocellchann", "mA/cm2",
 "drivenoise_Ocellchann", "mA/cm2",
 "celldrive_Ocellchann", "mA/cm2",
 "celldrivenoise_Ocellchann", "mA/cm2",
 "ina_Ocellchann", "mA/cm2",
 "ik_Ocellchann", "mA/cm2",
 "il_Ocellchann", "mA/cm2",
 "ia_Ocellchann", "mA/cm2",
 "ih_Ocellchann", "mA/cm2",
 0,0
};
 static double a0 = 0;
 static double b0 = 0;
 static double delta_t = 0.01;
 static double h0 = 0;
 static double mp0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double r0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "gna_Ocellchann", &gna_Ocellchann,
 "gnap_Ocellchann", &gnap_Ocellchann,
 "ena_Ocellchann", &ena_Ocellchann,
 "gk_Ocellchann", &gk_Ocellchann,
 "ek_Ocellchann", &ek_Ocellchann,
 "ga_Ocellchann", &ga_Ocellchann,
 "ea_Ocellchann", &ea_Ocellchann,
 "gh_Ocellchann", &gh_Ocellchann,
 "eh_Ocellchann", &eh_Ocellchann,
 "v50_Ocellchann", &v50_Ocellchann,
 "gl_Ocellchann", &gl_Ocellchann,
 "el_Ocellchann", &el_Ocellchann,
 "mtaup_Ocellchann", &mtaup_Ocellchann,
 "minfp_Ocellchann", &minfp_Ocellchann,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[0]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"Ocellchann",
 "drive_Ocellchann",
 "drivenoise_Ocellchann",
 0,
 "celldrive_Ocellchann",
 "celldrivenoise_Ocellchann",
 "ina_Ocellchann",
 "inap_Ocellchann",
 "ik_Ocellchann",
 "il_Ocellchann",
 "ia_Ocellchann",
 "ih_Ocellchann",
 0,
 "m_Ocellchann",
 "h_Ocellchann",
 "n_Ocellchann",
 "a_Ocellchann",
 "b_Ocellchann",
 "r_Ocellchann",
 "mp_Ocellchann",
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 37, _prop);
 	/*initialize range parameters*/
 	drive = -0.003;
 	drivenoise = 0;
 	_prop->param = _p;
 	_prop->param_size = 37;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 1, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _OCellTort_reg() {
	int _vectorized = 0;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 37, 1);
  hoc_register_dparam_semantics(_mechtype, 0, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Ocellchann /Users/danieltoker/Downloads/CODE_FIGURES_3_AND_4/OCellTort.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "OCellChann  ";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[7], _dlist1[7];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   rates ( _threadargscomma_ v ) ;
   Dm = ( minf - m ) / mtau ;
   Dh = ( hinf - h ) / htau ;
   Dn = ( ninf - n ) / ntau ;
   Da = ( ainf - a ) / atau ;
   Db = ( binf - b ) / btau ;
   Dr = ( rinf - r ) / rtau ;
   Dmp = ( minfp - mp ) / mtaup ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 rates ( _threadargscomma_ v ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / mtau )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / htau )) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / ntau )) ;
 Da = Da  / (1. - dt*( ( ( ( - 1.0 ) ) ) / atau )) ;
 Db = Db  / (1. - dt*( ( ( ( - 1.0 ) ) ) / btau )) ;
 Dr = Dr  / (1. - dt*( ( ( ( - 1.0 ) ) ) / rtau )) ;
 Dmp = Dmp  / (1. - dt*( ( ( ( - 1.0 ) ) ) / mtaup )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   rates ( _threadargscomma_ v ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / mtau)))*(- ( ( ( minf ) ) / mtau ) / ( ( ( ( - 1.0 ) ) ) / mtau ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / htau)))*(- ( ( ( hinf ) ) / htau ) / ( ( ( ( - 1.0 ) ) ) / htau ) - h) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / ntau)))*(- ( ( ( ninf ) ) / ntau ) / ( ( ( ( - 1.0 ) ) ) / ntau ) - n) ;
    a = a + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / atau)))*(- ( ( ( ainf ) ) / atau ) / ( ( ( ( - 1.0 ) ) ) / atau ) - a) ;
    b = b + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / btau)))*(- ( ( ( binf ) ) / btau ) / ( ( ( ( - 1.0 ) ) ) / btau ) - b) ;
    r = r + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / rtau)))*(- ( ( ( rinf ) ) / rtau ) / ( ( ( ( - 1.0 ) ) ) / rtau ) - r) ;
    mp = mp + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / mtaup)))*(- ( ( ( minfp ) ) / mtaup ) / ( ( ( ( - 1.0 ) ) ) / mtaup ) - mp) ;
   }
  return 0;
}
 
static int  rates (  double _lv ) {
   double _lalpha , _lbeta ;
  _lalpha = - 0.1 * ( _lv + 38.0 ) / ( exp ( - ( _lv + 38.0 ) / 10.0 ) - 1.0 ) ;
   _lbeta = 4.0 * exp ( - ( _lv + 65.0 ) / 18.0 ) ;
   mtau = 1.0 / ( _lalpha + _lbeta ) ;
   minf = _lalpha * mtau ;
   _lalpha = 0.07 * exp ( - ( _lv + 63.0 ) / 20.0 ) ;
   _lbeta = 1.0 / ( 1.0 + exp ( - ( _lv + 33.0 ) / 10.0 ) ) ;
   htau = 1.0 / ( _lalpha + _lbeta ) ;
   hinf = _lalpha * htau ;
   _lalpha = 0.018 * ( _lv - 25.0 ) / ( 1.0 - exp ( - ( _lv - 25.0 ) / 25.0 ) ) ;
   _lbeta = 0.0036 * ( _lv - 35.0 ) / ( exp ( ( _lv - 35.0 ) / 12.0 ) - 1.0 ) ;
   ntau = 1.0 / ( _lalpha + _lbeta ) ;
   ninf = _lalpha * ntau ;
   mtaup = 1.0 ;
   minfp = 1.0 / ( 1.0 + exp ( - ( _lv + 52.3 ) / 6.8 ) ) ;
   atau = 5.0 ;
   ainf = 1.0 / ( 1.0 + exp ( - ( _lv + 14.0 ) / 16.6 ) ) ;
   btau = 1.0 / ( 0.000009 / exp ( ( _lv - 26.0 ) / 18.5 ) + 0.014 / ( 0.2 + exp ( - ( _lv + 70.0 ) / 11.0 ) ) ) ;
   binf = 1.0 / ( 1.0 + exp ( ( _lv + 71.0 ) / 7.3 ) ) ;
   rinf = 1.0 / ( 1.0 + exp ( ( _lv - v50 ) / 10.2 ) ) ;
   rtau = ( 1.0 / ( exp ( - 14.59 - 0.086 * _lv ) + exp ( - 1.87 + 0.0701 * _lv ) ) ) ;
     return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 7;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 ();
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 7; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  a = a0;
  b = b0;
  h = h0;
  mp = mp0;
  m = m0;
  n = n0;
  r = r0;
 {
   rates ( _threadargscomma_ v ) ;
   m = minf ;
   h = hinf ;
   n = ninf ;
   a = ainf ;
   b = binf ;
   r = rinf ;
   mp = minfp ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   celldrive = - drive ;
   celldrivenoise = - drivenoise ;
   ik = gk * n * n * n * n * ( v - ek ) ;
   ina = gna * m * m * m * h * ( v - ena ) ;
   il = gl * ( v - el ) ;
   ia = ga * a * b * ( v - ea ) ;
   ih = gh * r * ( v - eh ) ;
   inap = gnap * mp * ( v - ena ) ;
   }
 _current += ina;
 _current += inap;
 _current += ik;
 _current += ia;
 _current += ih;
 _current += celldrive;
 _current += celldrivenoise;
 _current += il;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_v + .001);
 	{ _rhs = _nrn_current(_v);
 	}
 _g = (_g - _rhs)/.001;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
 { error =  states();
 if(error){fprintf(stderr,"at line 86 in file OCellTort.mod:\n        SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 }}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = m_columnindex;  _dlist1[0] = Dm_columnindex;
 _slist1[1] = h_columnindex;  _dlist1[1] = Dh_columnindex;
 _slist1[2] = n_columnindex;  _dlist1[2] = Dn_columnindex;
 _slist1[3] = a_columnindex;  _dlist1[3] = Da_columnindex;
 _slist1[4] = b_columnindex;  _dlist1[4] = Db_columnindex;
 _slist1[5] = r_columnindex;  _dlist1[5] = Dr_columnindex;
 _slist1[6] = mp_columnindex;  _dlist1[6] = Dmp_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/danieltoker/Downloads/CODE_FIGURES_3_AND_4/OCellTort.mod";
static const char* nmodl_file_text = 
  "TITLE OCellChann  \n"
  ": Cell model from  Tort et al. (2007)\n"
  ": Programmed by Adriano Tort, CBD, BU, 2008\n"
  "\n"
  "UNITS {\n"
  "        (mA) = (milliamp)\n"
  "        (mV) = (millivolt)\n"
  "}\n"
  " \n"
  "NEURON {\n"
  "	SUFFIX Ocellchann\n"
  "	NONSPECIFIC_CURRENT ina\n"
  "	NONSPECIFIC_CURRENT inap\n"
  "	NONSPECIFIC_CURRENT ik\n"
  "	NONSPECIFIC_CURRENT ia\n"
  "	NONSPECIFIC_CURRENT ih\n"
  "	NONSPECIFIC_CURRENT celldrive,celldrivenoise\n"
  "	NONSPECIFIC_CURRENT il\n"
  "	GLOBAL gna, gnap, ena, gk, ek, ga, ea, gh, eh, gl, el, minfp, mtaup\n"
  "	RANGE drive,drivenoise, htaup \n"
  "}\n"
  " \n"
  "PARAMETER {\n"
  "        v				(mV)\n"
  "        celsius			(degC)\n"
  "        gna= 0.030		(mho/cm2)\n"
  "	gnap = .0000005   	(mho/cm2)\n"
  "        ena= 60			(mV)\n"
  "        gk= 0.023		(mho/cm2)\n"
  "        ek= -100		(mV)\n"
  "        ga= 0.016		(mho/cm2)\n"
  "        ea= -90			(mV)\n"
  "        gh= 0.012		(mho/cm2)\n"
  "        eh= -32.9		(mV)\n"
  " 		v50=-84			(mV)\n"
  "		gl= 0.00005		(mho/cm2)\n"
  "        el= -70			(mV)\n"
  "		drive=-0.003	(mA/cm2)\n"
  "		drivenoise =0	(mA/cm2)\n"
  "}\n"
  " \n"
  " \n"
  "STATE {\n"
  "	m\n"
  "	h \n"
  "	n\n"
  "	a\n"
  "	b\n"
  "	r\n"
  "	mp\n"
  "}\n"
  " \n"
  " \n"
  "ASSIGNED {\n"
  "	celldrive		(mA/cm2)\n"
  "	celldrivenoise	(mA/cm2)\n"
  "	\n"
  "	ina		(mA/cm2) \n"
  " 	minf\n"
  "	mtau    (ms)\n"
  "	hinf\n"
  "	htau	(ms)\n"
  "\n"
  "	mtaup\n"
  "	minfp\n"
  "	inap\n"
  "	\n"
  "	ik		(mA/cm2)\n"
  "	ninf\n"
  "	ntau	(ms)\n"
  "	il		(mA/cm2)\n"
  "	\n"
  "	ia		(mA/cm2) \n"
  " 	ainf\n"
  "	atau    (ms)\n"
  "	binf\n"
  "	btau    (ms)\n"
  "	\n"
  "	ih		(mA/cm2) \n"
  " 	rinf\n"
  "	rtau    (ms)\n"
  "}\n"
  " \n"
  " \n"
  "BREAKPOINT {\n"
  "        SOLVE states METHOD cnexp\n"
  "		celldrive = -drive\n"
  "		celldrivenoise = -drivenoise\n"
  "        \n"
  "		ik=gk*n*n*n*n*(v-ek)\n"
  "		ina=gna*m*m*m*h*(v-ena)\n"
  "		il=gl*(v-el)\n"
  "        ia=ga*a*b*(v-ea)\n"
  "        ih=gh*r*(v-eh) \n"
  "	inap = gnap*mp * (v - ena)      \n"
  "}\n"
  " \n"
  " \n"
  "DERIVATIVE states { \n"
  "       rates(v)\n"
  "	   m'= (minf- m)/ mtau \n"
  "	   h'= (hinf- h)/ htau \n"
  "	   n'= (ninf- n)/ ntau \n"
  "	   a'= (ainf- a)/ atau\n"
  "	   b'= (binf- b)/ btau\n"
  "           r'= (rinf- r)/ rtau\n"
  "	   mp' = (minfp-mp)/mtaup \n"
  "}\n"
  "\n"
  "INITIAL { \n"
  "	rates(v)\n"
  "	m=minf\n"
  "	h=hinf\n"
  "	n=ninf\n"
  "	a=ainf\n"
  "	b=binf\n"
  "	r=rinf\n"
  "	mp=minfp\n"
  "}\n"
  "\n"
  "PROCEDURE rates(v (mV)) {\n"
  "LOCAL alpha, beta\n"
  "UNITSOFF \n"
  "\n"
  "	alpha = -0.1*(v+38)/(exp(-(v+38)/10)-1)\n"
  "	beta = 4*exp(-(v+65)/18)\n"
  "	mtau = 1/(alpha+beta)\n"
  "	minf = alpha*mtau	\n"
  "		\n"
  "	alpha = 0.07*exp(-(v+63)/20)\n"
  "  	beta =  1/(1+exp(-(v+33)/10))\n"
  "	htau = 1/(alpha+beta)\n"
  "	hinf = alpha*htau	\n"
  "	\n"
  "	alpha = 0.018*(v-25)/(1-exp(-(v-25)/25))\n"
  "  	beta =  0.0036*(v-35)/(exp((v-35)/12)-1)\n"
  "	ntau = 1/(alpha+beta)\n"
  "	ninf = alpha*ntau\n"
  "\n"
  "	mtaup = 1\n"
  "	minfp = 1/(1+exp(-(v+52.3)/6.8))\n"
  "	\n"
  "	atau=5\n"
  "	ainf=1/(1+exp(-(v+14)/16.6))\n"
  "	btau=1/(0.000009/exp((v-26)/18.5)+0.014/(0.2+exp(-(v+70)/11)))\n"
  "	binf=1/(1+exp((v+71)/7.3))\n"
  "	\n"
  "	rinf=1/(1+exp((v-v50)/10.2))\n"
  "	rtau=(1/(exp(-14.59-0.086*v)+exp(-1.87+0.0701*v))) \n"
  "	\n"
  "UNITSON\n"
  "}\n"
  ;
#endif

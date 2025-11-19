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
 
#define nrn_init _nrn_init__Icellchann
#define _nrn_initial _nrn_initial__Icellchann
#define nrn_cur _nrn_cur__Icellchann
#define _nrn_current _nrn_current__Icellchann
#define nrn_jacob _nrn_jacob__Icellchann
#define nrn_state _nrn_state__Icellchann
#define _net_receive _net_receive__Icellchann 
#define rates rates__Icellchann 
#define states states__Icellchann 
 
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
#define m _p[8]
#define m_columnindex 8
#define n _p[9]
#define n_columnindex 9
#define h _p[10]
#define h_columnindex 10
#define mp _p[11]
#define mp_columnindex 11
#define Dm _p[12]
#define Dm_columnindex 12
#define Dn _p[13]
#define Dn_columnindex 13
#define Dh _p[14]
#define Dh_columnindex 14
#define Dmp _p[15]
#define Dmp_columnindex 15
#define minf _p[16]
#define minf_columnindex 16
#define mtau _p[17]
#define mtau_columnindex 17
#define hinf _p[18]
#define hinf_columnindex 18
#define htau _p[19]
#define htau_columnindex 19
#define ninf _p[20]
#define ninf_columnindex 20
#define ntau _p[21]
#define ntau_columnindex 21
#define _g _p[22]
#define _g_columnindex 22
 
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
 "setdata_Icellchann", _hoc_setdata,
 "rates_Icellchann", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
#define el el_Icellchann
 double el = -65;
#define ek ek_Icellchann
 double ek = -90;
#define ena ena_Icellchann
 double ena = 60;
#define gl gl_Icellchann
 double gl = 0.0001;
#define gk gk_Icellchann
 double gk = 0.009;
#define gnap gnap_Icellchann
 double gnap = 5e-07;
#define gna gna_Icellchann
 double gna = 0.035;
#define mtaup mtaup_Icellchann
 double mtaup = 0;
#define minfp minfp_Icellchann
 double minfp = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gna_Icellchann", "mho/cm2",
 "gnap_Icellchann", "mho/cm2",
 "ena_Icellchann", "mV",
 "gk_Icellchann", "mho/cm2",
 "ek_Icellchann", "mV",
 "gl_Icellchann", "mho/cm2",
 "el_Icellchann", "mV",
 "drive_Icellchann", "mA/cm2",
 "drivenoise_Icellchann", "mA/cm2",
 "celldrive_Icellchann", "mA/cm2",
 "celldrivenoise_Icellchann", "mA/cm2",
 "ina_Icellchann", "mA/cm2",
 "ik_Icellchann", "mA/cm2",
 "il_Icellchann", "mA/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double mp0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "gna_Icellchann", &gna_Icellchann,
 "gnap_Icellchann", &gnap_Icellchann,
 "ena_Icellchann", &ena_Icellchann,
 "gk_Icellchann", &gk_Icellchann,
 "ek_Icellchann", &ek_Icellchann,
 "gl_Icellchann", &gl_Icellchann,
 "el_Icellchann", &el_Icellchann,
 "mtaup_Icellchann", &mtaup_Icellchann,
 "minfp_Icellchann", &minfp_Icellchann,
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
"Icellchann",
 "drive_Icellchann",
 "drivenoise_Icellchann",
 0,
 "celldrive_Icellchann",
 "celldrivenoise_Icellchann",
 "ina_Icellchann",
 "inap_Icellchann",
 "ik_Icellchann",
 "il_Icellchann",
 0,
 "m_Icellchann",
 "n_Icellchann",
 "h_Icellchann",
 "mp_Icellchann",
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 23, _prop);
 	/*initialize range parameters*/
 	drive = 0.001;
 	drivenoise = 0;
 	_prop->param = _p;
 	_prop->param_size = 23;
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

 void _IcellWangBuzsaki_reg() {
	int _vectorized = 0;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 23, 1);
  hoc_register_dparam_semantics(_mechtype, 0, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Icellchann /Users/danieltoker/Downloads/CODE_FIGURES_3_AND_4/IcellWangBuzsaki.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Icellchann";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[3], _dlist1[3];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   rates ( _threadargscomma_ v ) ;
   Dh = 5.0 * ( hinf - h ) / htau ;
   Dn = 5.0 * ( ninf - n ) / ntau ;
   Dmp = ( minfp - mp ) / mtaup ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 rates ( _threadargscomma_ v ) ;
 Dh = Dh  / (1. - dt*( ( ( 5.0 )*( ( ( - 1.0 ) ) ) ) / htau )) ;
 Dn = Dn  / (1. - dt*( ( ( 5.0 )*( ( ( - 1.0 ) ) ) ) / ntau )) ;
 Dmp = Dmp  / (1. - dt*( ( ( ( - 1.0 ) ) ) / mtaup )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   rates ( _threadargscomma_ v ) ;
    h = h + (1. - exp(dt*(( ( 5.0 )*( ( ( - 1.0 ) ) ) ) / htau)))*(- ( ( ( 5.0 )*( ( hinf ) ) ) / htau ) / ( ( ( 5.0 )*( ( ( - 1.0 ) ) ) ) / htau ) - h) ;
    n = n + (1. - exp(dt*(( ( 5.0 )*( ( ( - 1.0 ) ) ) ) / ntau)))*(- ( ( ( 5.0 )*( ( ninf ) ) ) / ntau ) / ( ( ( 5.0 )*( ( ( - 1.0 ) ) ) ) / ntau ) - n) ;
    mp = mp + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / mtaup)))*(- ( ( ( minfp ) ) / mtaup ) / ( ( ( ( - 1.0 ) ) ) / mtaup ) - mp) ;
   }
  return 0;
}
 
static int  rates (  double _lv ) {
   double _lalpha , _lbeta ;
  _lalpha = - 0.1 * ( _lv + 35.0 ) / ( exp ( - ( _lv + 35.0 ) / 10.0 ) - 1.0 ) ;
   _lbeta = 4.0 * exp ( - ( _lv + 60.0 ) / 18.0 ) ;
   minf = _lalpha / ( _lalpha + _lbeta ) ;
   _lalpha = 0.07 * exp ( - ( _lv + 58.0 ) / 20.0 ) ;
   _lbeta = 1.0 / ( exp ( - 0.1 * ( _lv + 28.0 ) ) + 1.0 ) ;
   htau = 1.0 / ( _lalpha + _lbeta ) ;
   hinf = _lalpha * htau ;
   mtaup = 1.0 ;
   minfp = 1.0 / ( 1.0 + exp ( - ( _lv + 52.3 ) / 6.8 ) ) ;
   _lalpha = 0.01 * ( _lv + 34.0 ) / ( 1.0 - exp ( - 0.1 * ( _lv + 34.0 ) ) ) ;
   _lbeta = 0.125 * exp ( - ( _lv + 44.0 ) / 80.0 ) ;
   ntau = 1.0 / ( _lalpha + _lbeta ) ;
   ninf = _lalpha * ntau ;
     return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 3;}
 
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
	for (_i=0; _i < 3; ++_i) {
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
  h = h0;
  mp = mp0;
  m = m0;
  n = n0;
 {
   rates ( _threadargscomma_ v ) ;
   n = ninf ;
   h = hinf ;
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
   ina = gna * minf * minf * minf * h * ( v - ena ) ;
   ik = gk * n * n * n * n * ( v - ek ) ;
   il = gl * ( v - el ) ;
   inap = gnap * mp * ( v - ena ) ;
   }
 _current += ina;
 _current += inap;
 _current += ik;
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
 if(error){fprintf(stderr,"at line 62 in file IcellWangBuzsaki.mod:\n        SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 }}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = h_columnindex;  _dlist1[0] = Dh_columnindex;
 _slist1[1] = n_columnindex;  _dlist1[1] = Dn_columnindex;
 _slist1[2] = mp_columnindex;  _dlist1[2] = Dmp_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/danieltoker/Downloads/CODE_FIGURES_3_AND_4/IcellWangBuzsaki.mod";
static const char* nmodl_file_text = 
  "TITLE Icellchann\n"
  ": Cell model from Wang and Buzsaki, J Neurosci 1996\n"
  ": Programmed by Adriano Tort, CBD, BU, 2008\n"
  "\n"
  "UNITS {\n"
  "        (mA) = (milliamp)\n"
  "        (mV) = (millivolt)\n"
  "}\n"
  " \n"
  "NEURON {\n"
  "	SUFFIX Icellchann\n"
  "	NONSPECIFIC_CURRENT ina\n"
  "	NONSPECIFIC_CURRENT inap\n"
  "	NONSPECIFIC_CURRENT ik\n"
  "	NONSPECIFIC_CURRENT celldrive, celldrivenoise\n"
  "	NONSPECIFIC_CURRENT il\n"
  "	GLOBAL gna, gnap, gk, ena, ek, gl, el, minfp, mtaup\n"
  "	RANGE drive,drivenoise, htaup\n"
  "}\n"
  " \n"
  "PARAMETER {\n"
  "        v				(mV)\n"
  "        celsius			(degC)\n"
  "        gna= 0.035		(mho/cm2)\n"
  "	gnap = .0000005   	(mho/cm2)\n"
  "        ena= 60			(mV)\n"
  "        gk= 0.009		(mho/cm2)\n"
  "        ek= -90			(mV)\n"
  "		gl= 0.0001		(mho/cm2)\n"
  "        el= -65			(mV)\n"
  "		drive=0.001		(mA/cm2)\n"
  "		drivenoise =0	(mA/cm2)\n"
  "		}\n"
  " \n"
  "STATE {\n"
  "	m\n"
  "	n\n"
  "	h \n"
  "	mp\n"
  "}\n"
  " \n"
  "ASSIGNED {\n"
  "	celldrive		(mA/cm2)\n"
  "	celldrivenoise	(mA/cm2)\n"
  "	\n"
  "	ina		(mA/cm2) \n"
  " 	minf\n"
  "	mtau   	(ms)\n"
  "	hinf\n"
  "	htau    (ms)\n"
  "	mtaup\n"
  "	minfp\n"
  "	inap\n"
  "	ik		(mA/cm2)\n"
  "	ninf\n"
  "	ntau	(ms)\n"
  "	\n"
  "	il		(mA/cm2) \n"
  "}\n"
  " \n"
  "BREAKPOINT {\n"
  "        SOLVE states METHOD cnexp\n"
  "		celldrive = -drive\n"
  "		celldrivenoise = -drivenoise\n"
  "		\n"
  "        ina=gna*minf*minf*minf*h*(v-ena)\n"
  "		ik=gk*n*n*n*n*(v-ek)\n"
  "		il=gl*(v-el)  \n"
  "		inap = gnap*mp * (v - ena)    \n"
  "}\n"
  " \n"
  "DERIVATIVE states { \n"
  "       rates(v)\n"
  "	   h'= 5*(hinf- h)/ htau\n"
  "	   n'= 5*(ninf- n)/ ntau \n"
  "	   mp' = (minfp-mp)/mtaup\n"
  "}\n"
  "\n"
  "\n"
  "INITIAL { \n"
  "	rates(v)\n"
  "	n=ninf\n"
  "	h=hinf\n"
  "	mp=minfp \n"
  "	}\n"
  "\n"
  "PROCEDURE rates(v (mV)) {\n"
  "LOCAL alpha, beta\n"
  "UNITSOFF \n"
  "\n"
  "	alpha = -0.1*(v+35)/(exp(-(v+35)/10)-1)\n"
  "	beta = 4*exp(-(v+60)/18)\n"
  "	minf=alpha/(alpha+beta)\n"
  "	\n"
  "	alpha = 0.07*exp(-(v+58)/20)\n"
  "	beta = 1/(exp(-0.1*(v+28))+1)\n"
  "	htau=1/(alpha+beta)\n"
  "	hinf=alpha*htau\n"
  "\n"
  "	mtaup = 1\n"
  "	minfp = 1/(1+exp(-(v+52.3)/6.8))\n"
  "	\n"
  "	alpha = 0.01*(v+34)/(1-exp(-0.1*(v+34)))\n"
  "	beta = 0.125*exp(-(v+44)/80)\n"
  "	ntau=1/(alpha+beta)\n"
  "	ninf=alpha*ntau	\n"
  "	\n"
  "UNITSON\n"
  "}\n"
  ;
#endif

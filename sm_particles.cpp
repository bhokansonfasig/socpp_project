#include "sm_particles.hpp"

// Standard Model particle properties getter overrides
const double sm_props::get_mass_in_kilograms() const
{
    // Convert MeV to kg
    return mass_ * 1.7826619e-30;
}

const double sm_props::get_charge_in_coulombs() const
{
    // Convert factor of electron charge to coulombs
    return charge_ * 1.60217662e-19;
}

const double sm_props::get_spin_quantum_number() const
{
    // Confirm that spin is a factor of 1/2
    double check = 2*spin_;
    if (check == std::floor(check)) {return spin_;}
    else
    {
        std::string name;
        try
        {
            name = get_fullname();
            name = " ("+name+")";
        }
        catch (...) {name = "";}

        std::ostringstream oss;
        oss << "Spin of Standard Model particle" << name << " must be a whole or half integer (not " << spin_ << ")";
        throw std::invalid_argument(oss.str());
    }
}



std::map<sm_particle, sm_props> sm_properties =
{
    {sm_particle::null, sm_props{{"null","","unknown"}, 0, 0, 0}},
    // Bosons
    {sm_particle::photon, sm_props{{"gamma","photon"}, 0, 0, 1}},
    {sm_particle::W_m, sm_props{{"W-","W_m","negative W boson"}, 80385, -1, 1}},
    {sm_particle::W_p, sm_props{{"W+","W_p","positive W boson"}, 80385, 1, 1}},
    {sm_particle::Z, sm_props{{"Z","Z boson"}, 91187.5, 0, 1}},
    {sm_particle::gluon, sm_props{{"g","gluon"}, 0, 0, 1}},
    {sm_particle::higgs, sm_props{{"h","higgs","higgs boson"}, 125090, 0, 0}},
    // Leptons
    {sm_particle::e_m, sm_props{{"e-","e_m","electron"}, 0.511, -1, 1/2.}},
    {sm_particle::e_p, sm_props{{"e+","e_p","positron"}, 0.511, 1, 1/2.}},
    {sm_particle::mu_m, sm_props{{"mu-","mu_m","muon"}, 105.7, -1, 1/2.}},
    {sm_particle::mu_p, sm_props{{"mu+","mu_p","anti-muon"}, 105.7, 1, 1/2.}},
    {sm_particle::tau_m, sm_props{{"tau-","tau_m","tau"}, 1776.86, -1, 1/2.}},
    {sm_particle::tau_p, sm_props{{"tau+","tau_p","anti-tau"}, 1776.86, 1, 1/2.}},
    {sm_particle::nuE, sm_props{{"nuE","electron neutrino"}, 0, 0, 1/2.}},
    {sm_particle::nuEbar, sm_props{{"nuEbar","electron anti-neutrino"}, 0, 0, 1/2.}},
    {sm_particle::nuU, sm_props{{"nuU","nuMu","muon neutrino"}, 0, 0, 1/2.}},
    {sm_particle::nuUbar, sm_props{{"nuUbar","nuMubar","muon anti-neutrino"}, 0, 0, 1/2.}},
    {sm_particle::nuT, sm_props{{"nuT","nuTau","tau neutrino"}, 0, 0, 1/2.}},
    {sm_particle::nuTbar, sm_props{{"nuTbar","nuTaubar","tau anti-neutrino"}, 0, 0, 1/2.}},
    // Quarks
    {sm_particle::u, sm_props{{"u","up"}, 2.2, 2/3., 1/2.}},
    {sm_particle::ubar, sm_props{{"ubar","anti-up"}, 2.2, -2/3., 1/2.}},
    {sm_particle::d, sm_props{{"d","down"}, 4.6, -1/3., 1/2.}},
    {sm_particle::dbar, sm_props{{"dbar","anti-down"}, 4.6, 1/3., 1/2.}},
    {sm_particle::c, sm_props{{"c","charm"}, 1280, 2/3., 1/2.}},
    {sm_particle::cbar, sm_props{{"cbar","anti-charm"}, 1280, -2/3., 1/2.}},
    {sm_particle::s, sm_props{{"s","strange"}, 96, -1/3., 1/2.}},
    {sm_particle::sbar, sm_props{{"sbar","anti-strange"}, 96, 1/3., 1/2.}},
    {sm_particle::t, sm_props{{"t","top"}, 173100, 2/3., 1/2.}},
    {sm_particle::tbar, sm_props{{"tbar","anti-top"}, 173100, -2/3., 1/2.}},
    {sm_particle::b, sm_props{{"b","bottom"}, 4180, -1/3., 1/2.}},
    {sm_particle::bbar, sm_props{{"bbar","anti-bottom"}, 4180, 1/3., 1/2.}},
    // Pseudoscalar mesons
    {sm_particle::pi_m, sm_props{{"pi-","pi_m","negative pion"}, 139.57018, -1, 0}},
    {sm_particle::pi_p, sm_props{{"pi+","pi_p","positive pion"}, 139.57018, 1, 0}},
    {sm_particle::pi0, sm_props{{"pi0","pion","neutral pion"}, 134.9766, 0, 0}},
    {sm_particle::eta, sm_props{{"eta","eta meson"}, 547.862, 0, 0}},
    {sm_particle::etaprime, sm_props{{"etaprime","eta prime","eta prime meson"}, 957.78, 0, 0}},
    {sm_particle::etac, sm_props{{"etac","charmed eta","charmed eta meson"}, 2983.6, 0, 0}},
    {sm_particle::etab, sm_props{{"etab","bottom eta","bottom eta meson"}, 9398.0, 0, 0}},
    {sm_particle::K_m, sm_props{{"K-","K_m","negative kaon"}, 493.677, -1, 0}},
    {sm_particle::K_p, sm_props{{"K+","K_p","positive kaon"}, 493.677, 1, 0}},
    {sm_particle::K0, sm_props{{"K0","kaon","neutral kaon"}, 497.614, 0, 0}},
    {sm_particle::K0bar, sm_props{{"K0bar","anti-kaon"}, 497.614, 0, 0}},
    {sm_particle::K0short, sm_props{{"Kshort","K0short","short kaon"}, 497.614, 0, 0}},
    {sm_particle::K0long, sm_props{{"Klong","K0long","long kaon"}, 497.614, 0, 0}},
    {sm_particle::D_m, sm_props{{"D-","D_m","negative D","negative D meson"}, 1869.61, -1, 0}},
    {sm_particle::D_p, sm_props{{"D+","D_p","positive D","positive D meson"}, 1869.61, 1, 0}},
    {sm_particle::D0, sm_props{{"D","D0","D meson","neutral D meson"}, 1864.84, 0, 0}},
    {sm_particle::D0bar, sm_props{{"D0bar","anti-D","anti-D meson"}, 1864.84, 0, 0}},
    {sm_particle::D_ms, sm_props{{"D-s","Ds-","D_ms","negative strange D meson"}, 1968.30, -1, 0}},
    {sm_particle::D_ps, sm_props{{"D+s","Ds+","D_ps","positive strange D meson"}, 1968.30, 1, 0}},
    {sm_particle::B_m, sm_props{{"B-","B_m","negative B","negative B meson"}, 5279.26, -1, 0}},
    {sm_particle::B_p, sm_props{{"B+","B_p","positive B","positive B meson"}, 5279.26, 1, 0}},
    {sm_particle::B0, sm_props{{"B","B0","B meson","neutral B","neutral B meson"}, 5279.58, 0, 0}},
    {sm_particle::B0bar, sm_props{{"B0bar","anti-B","anti-B meson"}, 5279.58, 0, 0}},
    {sm_particle::B0s, sm_props{{"B0s","Bs0","strange B meson"}, 5366.77, 0, 0}},
    {sm_particle::B0sbar, sm_props{{"B0sbar","Bs0bar"}, 5366.77, 0, 0}},
    {sm_particle::B_mc, sm_props{{"B-c","Bc-","B_mc","negative charmed B meson"}, 6275.6, -1, 0}},
    {sm_particle::B_pc, sm_props{{"B+c","Bc+","B_pc","positive charmed B meson"}, 6275.6, 1, 0}},
    // Vector mesons
    {sm_particle::rho_m, sm_props{{"rho-","rho_m","negative rho","negative rho meson"}, 775.11, -1, 1}},
    {sm_particle::rho_p, sm_props{{"rho+","rho_p","positive rho","positive rho meson"}, 775.11, 1, 1}},
    {sm_particle::rho0, sm_props{{"rho","rho0","neutral rho","neutral rho meson"}, 775.26, 0, 1}},
    {sm_particle::omega, sm_props{{"omega","omega meson"}, 782.65, 0, 1}},
    {sm_particle::phi, sm_props{{"phi","phi meson"}, 1019.461, 0, 1}},
    {sm_particle::Jpsi, sm_props{{"J","psi","Jpsi","J/psi"}, 3096.916, 0, 1}},
    {sm_particle::upsilon, sm_props{{"upsilon","upsilon meson"}, 9460.30, 0, 1}},
    {sm_particle::vK_m, sm_props{{"vK-","vK_m","negative vector kaon"}, 891.66, -1, 1}},
    {sm_particle::vK_p, sm_props{{"vK+","vK_p","positive vector kaon"}, 891.66, 1, 1}},
    {sm_particle::vK0, sm_props{{"vK","vK0","neutral vector kaon"}, 895.81, 0, 1}},
    {sm_particle::vK0bar, sm_props{{"vKbar","vK0bar","vector anti-kaon"}, 895.81, 0, 1}},
    {sm_particle::vD_m, sm_props{{"vD-","vD_m","negative vector D meson"}, 2010.26, -1, 1}},
    {sm_particle::vD_p, sm_props{{"vD+","vD_p","positive vector D meson"}, 2010.26, 1, 1}},
    {sm_particle::vD0, sm_props{{"vD","vD0","neutral vector D meson"}, 2006.96, 0, 1}},
    {sm_particle::vD0bar, sm_props{{"vDbar","vD0bar","vector anti-D meson"}, 2006.96, 0, 1}},
    {sm_particle::vD_ms, sm_props{{"vD-s","vDs-","vD_ms","negative strange vector D meson"}, 2112.1, -1, 1}},
    {sm_particle::vD_ps, sm_props{{"vD+s","vDs+","vD_ps","postiive strange vector D meson"}, 2112.1, 1, 1}},
    {sm_particle::vB_m, sm_props{{"vB-","vB_m","negative vector B meson"}, 5325.2, -1, 1}},
    {sm_particle::vB_p, sm_props{{"vB+","vB_p","positive vector B meson"}, 5325.2, 1, 1}},
    {sm_particle::vB0, sm_props{{"vB","vB0","neutral vector B meson"}, 5325.2, 0, 1}},
    {sm_particle::vB0bar, sm_props{{"vBbar","vB0bar","vector anti-B meson"}, 5325.2, 0, 1}},
    {sm_particle::vB0s, sm_props{{"vBs","vB0s","vBs0","neutral strange vector B meson"}, 5415.4, 0, 1}},
    {sm_particle::vB0sbar, sm_props{{"vBsbar","vB0sbar","vBs0bar","strange vector anti-B meson"}, 5415.4, 0, 1}},
    {sm_particle::vB_mc, sm_props{{"vB-c","vBc-","vB_mc","negative charmed vector B meson"}, -1, -1, 1}},
    {sm_particle::vB_pc, sm_props{{"vB+c","vBc+","vB_pc","positive charmed vector B meson"}, -1, 1, 1}},
    // J = +/- 1/2. baryons
    {sm_particle::proton, sm_props{{"p+","p","uud","proton"}, 938.272046, 1, 1/2.}},
    {sm_particle::neutron, sm_props{{"n","n0","udd","neutron"}, 939.565379, 0, 1/2.}},
    {sm_particle::lambda, sm_props{{"lambda","uds","lambda"}, 1115.683, 0, 1/2.}},
    {sm_particle::lambdac, sm_props{{"lambdac","udc","charmed lambda"}, 2286.46, 1, 1/2.}},
    {sm_particle::lambdab, sm_props{{"lambdab","udb","bottom lambda"}, 5619.4, 0, 1/2.}},
    {sm_particle::sigma_p, sm_props{{"sigma+","sigma_p","uus","positive sigma"}, 1189.37, 1, 1/2.}},
    {sm_particle::sigma0, sm_props{{"sigma","sigma0","uds","neutral sigma"}, 1192.642, 0, 1/2.}},
    {sm_particle::sigma_m, sm_props{{"sigma-","sigma_m","dds","negative sigma"}, 1197.449, -1, 1/2.}},
    {sm_particle::sigma_ppc, sm_props{{"sigma++c","sigmac++","sigma_ppc","uuc","double positive charmed sigma"}, 2453.98, 2, 1/2.}},
    {sm_particle::sigma_pc, sm_props{{"sigma+c","sigmac+","sigma_pc","udc","positive charmed sigma"}, 2452.9, 1, 1/2.}},
    {sm_particle::sigma0c, sm_props{{"sigmac","sigma0c","sigmac0","ddc","neutral charmed sigma"}, 2453.74, 0, 1/2.}},
    {sm_particle::sigma_pb, sm_props{{"sigma+b","sigmab+","sigma_pb","uub","positive bottom sigma"}, 5811.3, 1, 1/2.}},
    {sm_particle::sigma0b, sm_props{{"sigmab","sigma0b","sigmab0","udb","neutral bottom sigma"}, -1, 0, 1/2.}},
    {sm_particle::sigma_mb, sm_props{{"sigma-b","sigmab-","sigma_mb","ddb","negative bottom sigma"}, 5815.5, -1, 1/2.}},
    {sm_particle::xi0, sm_props{{"xi","xi0","uss","neutral xi"}, 1314.86, 0, 1/2.}},
    {sm_particle::xi_m, sm_props{{"xi-","xi_m","dss","negative xi"}, 1321.71, -1, 1/2.}},
    {sm_particle::xi_pc, sm_props{{"xi+c","xic+","xi_pc","usc","positive charmed xi"}, 2467.8, 1, 1/2.}},
    {sm_particle::xi0c, sm_props{{"xic","xi0c","xic0","dsc","neutral charmed xi"}, 2470.88, 0, 1/2.}},
    {sm_particle::xi_pcprime, sm_props{{"xi+cprime","xic+prime","xi_pcprime","usc","positive charmed xi prime"}, 2575.6, 1, 1/2.}},
    {sm_particle::xi0cprime, sm_props{{"xicprime","xi0cprime","xic0prime","dsc","neutral charmed xi prime"}, 2577.9, 0, 1/2.}},
    {sm_particle::xi_ppcc, sm_props{{"xi++cc","xicc++","xi_ppcc","ucc","double positive double charmed xi"}, 3621.4, 2, 1/2.}},
    {sm_particle::xi_pcc, sm_props{{"xi+cc","xicc+","xi_pcc","dcc","positive double charmed xi"}, -1, 1, 1/2.}},
    {sm_particle::xi0b, sm_props{{"xib","xi0b","xib0","usb","neutral cascade B","neutral bottom xi"}, 5787.8, 0, 1/2.}},
    {sm_particle::xi_mb, sm_props{{"xi-b","xib-","xi_mb","dsb","negative cascade B","negative bottom xi"}, 5791.1, -1, 1/2.}},
    {sm_particle::xi0bprime, sm_props{{"xibprime","xi0bprime","xib0prime","usb","neutral bottom xi prime"}, -1, 0, 1/2.}},
    {sm_particle::xi_mbprime, sm_props{{"xi-bprime","xib-prime","xi_mbprime","dsb","negative bottom xi prime"}, -1, -1, 1/2.}},
    {sm_particle::xi0bb, sm_props{{"xibb","xi0bb","xibb0","ubb","neutral double bottom xi"}, -1, 0, 1/2.}},
    {sm_particle::xi_mbb, sm_props{{"xi-bb","xibb-","xi_mbb","dbb","negative double bottom xi"}, -1, -1, 1/2.}},
    {sm_particle::xi_pcb, sm_props{{"xi+cb","xicb+","xi_pcb","ucb","positive charmed bottom xi"}, -1, 1, 1/2.}},
    {sm_particle::xi0cb, sm_props{{"xicb","xi0cb","xicb0","dcb","neutral charmed bottom xi"}, -1, 0, 1/2.}},
    {sm_particle::xi_pcbprime, sm_props{{"xi+cbprime","xicb+prime","xi_pcbprime","ucb","positive charmed bottom xi prime"}, -1, 1, 1/2.}},
    {sm_particle::xi0cbprime, sm_props{{"xicbprime","xi0cbprime","xicb0prime","dcb","neutral charmed bottom xi prime"}, -1, 0, 1/2.}},
    {sm_particle::omega0c, sm_props{{"omegac","omega0c","ssc","neutral charmed omega"}, 2695.2, 0, 1/2.}},
    {sm_particle::omega_mb, sm_props{{"omega-b","omegab-","omega_mb","ssb","negative bottom omega"}, 6071, -1, 1/2.}},
    {sm_particle::omega_pcc, sm_props{{"omega+cc","omegacc+","omega_pcc","scc","positive double charmed omega"}, -1, 1, 1/2.}},
    {sm_particle::omega0cb, sm_props{{"omegacb","omega0cb","omegacb0","scb","neutral charmed bottom omega"}, -1, 0, 1/2.}},
    {sm_particle::omega0cbprime, sm_props{{"omegacbprime","omega0cbprime","omegacb0prime","scb","neutral charmed bottom omega prime"}, -1, 0, 1/2.}},
    {sm_particle::omega_mbb, sm_props{{"omega-bb","omegabb-","omega_mbb","sbb","negative double bottom omega"}, -1, -1, 1/2.}},
    {sm_particle::omega_pccb, sm_props{{"omega+ccb","omegaccb+","omega_pccb","ccb","positive double charmed bottom omega"}, -1, 1, 1/2.}},
    {sm_particle::omega0cbb, sm_props{{"omegacbb","omega0cbb","omegacbb0","cbb","neutral charmed double bottom omega"}, -1, 0, 1/2.}},
    // J = +/- 3/2. Baryons
    {sm_particle::delta_pp, sm_props{{"delta++","delta_pp","uuu","double positive delta"}, 1232, 2, 3/2.}},
    {sm_particle::delta_p, sm_props{{"delta+","delta_p","uud","positive delta"}, 1232, 1, 3/2.}},
    {sm_particle::delta0, sm_props{{"delta","delta0","udd","neutral delta"}, 1232, 0, 3/2.}},
    {sm_particle::delta_m, sm_props{{"delta-","delta_m","ddd","negative delta"}, 1232, -1, 3/2.}},
    {sm_particle::sigma3_p, sm_props{{"sigma3+","sigma3_p","uus","positive sigma dot"}, 1382.8, 1, 3/2.}},
    {sm_particle::sigma30, sm_props{{"sigma3","sigma30","uds","neutral sigma dot"}, 1383.7, 0, 3/2.}},
    {sm_particle::sigma3_m, sm_props{{"sigma3-","sigma3_m","dds","negative sigma dot"}, 1387.2, -1, 3/2.}},
    {sm_particle::sigma3_ppc, sm_props{{"sigma3++c","sigma3c++","sigma3_ppc","uuc","double positive charmed sigma dot"}, 2517.9, 2, 3/2.}},
    {sm_particle::sigma3_pc, sm_props{{"sigma3+c","sigma3c+","sigma3_pc","udc","positive charmed sigma dot"}, 2517.5, 1, 3/2.}},
    {sm_particle::sigma30c, sm_props{{"sigma3c","sigma30c","sigma3c0","ddc","neutral charmed sigma dot"}, 2518.8, 0, 3/2.}},
    {sm_particle::sigma3_pb, sm_props{{"sigma3+b","sigma3b+","sigma3_pb","uub","positive bottom sigma dot"}, 5832.1, 1, 3/2.}},
    {sm_particle::sigma30b, sm_props{{"sigma3b","sigma30b","sigma3b0","udb","neutral bottom sigma dot"}, -1, 0, 3/2.}},
    {sm_particle::sigma3_mb, sm_props{{"sigma3-b","sigma3b-","sigma3_mb","ddb","negative bottom sigma dot"}, 5835.1, -1, 3/2.}},
    {sm_particle::xi30, sm_props{{"xi3","xi30","uss","neutral xi dot"}, 1531.8, 0, 3/2.}},
    {sm_particle::xi3_m, sm_props{{"xi3-","xi3_m","dss","negative xi dot"}, 1535.0, -1, 3/2.}},
    {sm_particle::xi3_pc, sm_props{{"xi3+c","xi3c+","xi3_pc","usc","positive charmed xi dot"}, 2645.9, 1, 3/2.}},
    {sm_particle::xi30c, sm_props{{"xi3c","xi30c","xi3c0","dsc","neutral charmed xi dot"}, 1645.9, 0, 3/2.}},
    {sm_particle::xi3_ppcc, sm_props{{"xi3++cc","xi3cc++","xi3_ppcc","ucc","double positive double charmed xi dot"}, -1, 2, 3/2.}},
    {sm_particle::xi3_pcc, sm_props{{"xi3+cc","xi3cc+","xi3_pcc","dcc","positive double charmed xi dot"}, -1, 1, 3/2.}},
    {sm_particle::xi30b, sm_props{{"xi3b","xi30b","xi3b0","usb","neutral bottom xi dot"}, 5945.5, 0, 3/2.}},
    {sm_particle::xi3_mb, sm_props{{"xi3-b","xi3b-","xi3_mb","dsb","negative bottom xi dot"}, -1, -1, 3/2.}},
    {sm_particle::xi30bb, sm_props{{"xi3bb","xi30bb","xi3bb0","ubb","neutral double bottom xi dot"}, -1, 0, 3/2.}},
    {sm_particle::xi3_mbb, sm_props{{"xi3-bb","xi3bb-","xi3_mbb","dbb","negative double bottom xi dot"}, -1, -1, 3/2.}},
    {sm_particle::xi3_pcb, sm_props{{"xi3+cb","xi3cb+","xi3_pcb","ucb","positive charmed bottom xi dot"}, -1, 1, 3/2.}},
    {sm_particle::xi30cb, sm_props{{"xi3cb","xi30cb","xi3cb0","dcb","neutral charmed bottom xi dot"}, -1, 0, 3/2.}},
    {sm_particle::omega_m, sm_props{{"omega-","omega_m","sss","negative omega"}, 1672.45, -1, 3/2.}},
    {sm_particle::omega30c, sm_props{{"omega3c","omega30c","omega3c0","ssc","neutral charmed omega dot"}, 2765.9, 0, 3/2.}},
    {sm_particle::omega3_mb, sm_props{{"omega3-b","omega3b-","omega3_mb","ssb","negative bottom omega dot"}, -1, -1, 3/2.}},
    {sm_particle::omega3_pcc, sm_props{{"omega3+cc","omega3cc+","omega3_pcc","scc","positive double charmed omega dot"}, -1, 1, 3/2.}},
    {sm_particle::omega30cb, sm_props{{"omega3cb","omega30cb","omega3cb0","scb","neutral charmed bottom omega dot"}, -1, 0, 3/2.}},
    {sm_particle::omega3_mbb, sm_props{{"omega3-bb","omega3bb-","omega3_mbb","sbb","negative double bottom omega dot"}, -1, -1, 3/2.}},
    {sm_particle::omega_ppccc, sm_props{{"omega++ccc","omegaccc++","omega_ppccc","ccc","triple charmed omega","double positive triple charmed omega"}, -1, 2, 3/2.}},
    {sm_particle::omega3_pccb, sm_props{{"omega3+ccb","omega3ccb+","omega3_pccb","ccb","double charmed bottom omega","positive double charmed bottom omega"}, -1, 1, 3/2.}},
    {sm_particle::omega30cbb, sm_props{{"omega3cbb","omega30cbb","omega3cbb0","cbb","charmed double bottom omega","neutral charmed double bottom omega"}, -1, 0, 3/2.}},
    {sm_particle::omega_mbbb, sm_props{{"omega-bbb","omega_mbbb","bbb","triple bottom omega","negative triple bottom omega"}, -1, -1, 3/2.}}
};

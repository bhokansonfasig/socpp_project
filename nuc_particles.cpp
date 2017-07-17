#include "nuc_particles.hpp"

// Standard Model particle properties getter overrides
const double nuc_props::get_mass_in_kilograms() const
{
    // Convert amu to kg
    return mass_ * 1.660539e-27;
}

const double nuc_props::get_charge_in_coulombs() const
{
    // Convert factor of electron charge to coulombs
    return charge_ * 1.60217662e-19;
}

const double nuc_props::get_spin_quantum_number() const
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
        oss << "Spin of nucleus" << name << " must be a whole or half integer (not " << spin_ << ")";
        throw std::invalid_argument(oss.str());
    }
}



std::map<nuc_particle, nuc_props> nuc_properties =
{
    {nuc_particle::null, nuc_props{{"null","","unknown"}, 0, 0, 0}},
    // Hydrogen
    {nuc_particle::h1n, nuc_props{{"h1n","H-1 nucleus"}, 1.007825, 1, 1/2.}},
    {nuc_particle::h2n, nuc_props{{"h2n","H-2 nucleus"}, 2.014102, 1, 1}},
    {nuc_particle::h3n, nuc_props{{"h3n","H-3 nucleus"}, 3.016049, 1, 1/2.}},
    // Helium
    {nuc_particle::he3n, nuc_props{{"he3n","He-3 nucleus"}, 3.016029, 2, 1/2.}},
    {nuc_particle::he4n, nuc_props{{"he4n","He-4 nucleus"}, 4.002603, 2, 0}},
    // Lithium
    {nuc_particle::li6n, nuc_props{{"li6n","Li-6 nucleus"}, 6.015122, 3, 1}},
    {nuc_particle::li7n, nuc_props{{"li7n","Li-7 nucleus"}, 7.016004, 3, 3/2.}},
    // Beryllium
    {nuc_particle::be9n, nuc_props{{"be9n","Be-9 nucleus"}, 9.012182, 4, 3/2.}},
    // Boron
    {nuc_particle::b10n, nuc_props{{"b10n","B-10 nucleus"}, 10.012937, 5, 3}},
    {nuc_particle::b11n, nuc_props{{"b11n","B-11 nucleus"}, 11.009305, 5, 3/2.}},
    // Carbon
    {nuc_particle::c12n, nuc_props{{"c12n","C-12 nucleus"}, 12.0, 6, 0}},
    {nuc_particle::c13n, nuc_props{{"c13n","C-13 nucleus"}, 13.003355, 6, 1/2.}},
    {nuc_particle::c14n, nuc_props{{"c14n","C-14 nucleus"}, 14.003242, 6, 0}},
    // Nitrogen
    {nuc_particle::n14n, nuc_props{{"n14n","N-14 nucleus"}, 14.003074, 7, 1}},
    {nuc_particle::n15n, nuc_props{{"n15n","N-15 nucleus"}, 15.000109, 7, 1/2.}},
    // Oxygen
    {nuc_particle::o16n, nuc_props{{"o16n","O-16 nucleus"}, 15.994915, 8, 0}},
    {nuc_particle::o17n, nuc_props{{"o17n","O-17 nucleus"}, 16.999132, 8, 5/2.}},
    {nuc_particle::o18n, nuc_props{{"o18n","O-18 nucleus"}, 17.999160, 8, 0}},
    // Flourine
    {nuc_particle::f19n, nuc_props{{"f19n","F-19 nucleus"}, 18.998403, 9, 1/2.}},
    // Neon
    {nuc_particle::ne20n, nuc_props{{"ne20n","Ne-20 nucleus"}, 19.992440, 10, 0}},
    {nuc_particle::ne21n, nuc_props{{"ne21n","Ne-21 nucleus"}, 20.993847, 10, 3/2.}},
    {nuc_particle::ne22n, nuc_props{{"ne22n","Ne-22 nucleus"}, 21.991386, 10, 0}},
    // Sodium
    {nuc_particle::na23n, nuc_props{{"na23n","Na-23 nucleus"}, 22.989770, 11, 3/2.}},
    // Magnesium
    {nuc_particle::mg24n, nuc_props{{"mg24n","Mg-24 nucleus"}, 23.985042, 12, 0}},
    {nuc_particle::mg25n, nuc_props{{"mg25n","Mg-25 nucleus"}, 24.985837, 12, 5/2.}},
    {nuc_particle::mg26n, nuc_props{{"mg26n","Mg-26 nucleus"}, 25.982593, 12, 0}},
    // Aluminium
    {nuc_particle::al27n, nuc_props{{"al27n","Al-27 nucleus"}, 26.981538, 13, 5/2.}},
    // Silicon
    {nuc_particle::si28n, nuc_props{{"si28n","Si-28 nucleus"}, 27.976927, 14, 0}},
    {nuc_particle::si29n, nuc_props{{"si29n","Si-29 nucleus"}, 28.976495, 14, 1/2.}},
    {nuc_particle::si30n, nuc_props{{"si30n","Si-30 nucleus"}, 29.973770, 14, 0}},
    // Phosphorous
    {nuc_particle::p31n, nuc_props{{"p31n","P-31 nucleus"}, 30.973762, 15, 1/2.}},
    // Sulfur
    {nuc_particle::s32n, nuc_props{{"s32n","S-32 nucleus"}, 31.972071, 16, 0}},
    {nuc_particle::s33n, nuc_props{{"s33n","S-33 nucleus"}, 32.971458, 16, 3/2.}},
    {nuc_particle::s34n, nuc_props{{"s34n","S-34 nucleus"}, 33.967867, 16, 0}},
    {nuc_particle::s36n, nuc_props{{"s36n","S-36 nucleus"}, 35.967081, 16, 0}},
    // Chlorine
    {nuc_particle::cl35n, nuc_props{{"cl35n","Cl-35 nucleus"}, 34.968853, 17, 3/2.}},
    {nuc_particle::cl37n, nuc_props{{"cl37n","Cl-37 nucleus"}, 36.965903, 17, 3/2.}},
    // Argon
    {nuc_particle::ar36n, nuc_props{{"ar36n","Ar-36 nucleus"}, 35.967546, 18, 0}},
    {nuc_particle::ar38n, nuc_props{{"ar38n","Ar-38 nucleus"}, 37.962732, 18, 0}},
    {nuc_particle::ar40n, nuc_props{{"ar40n","Ar-40 nucleus"}, 39.962383, 18, 0}},
    // Potassium
    {nuc_particle::k39n, nuc_props{{"k39n","K-39 nucleus"}, 38.963707, 19, 3/2.}},
    {nuc_particle::k40n, nuc_props{{"k40n","K-40 nucleus"}, 39.963999, 19, 4}},
    {nuc_particle::k41n, nuc_props{{"k41n","K-41 nucleus"}, 40.961826, 19, 3/2.}},
    // Calcium
    {nuc_particle::ca40n, nuc_props{{"ca40n","Ca-40 nucleus"}, 39.962591, 20, 0}},
    {nuc_particle::ca42n, nuc_props{{"ca42n","Ca-42 nucleus"}, 41.958618, 20, 0}},
    {nuc_particle::ca43n, nuc_props{{"ca43n","Ca-43 nucleus"}, 42.958767, 20, 7/2.}},
    {nuc_particle::ca44n, nuc_props{{"ca44n","Ca-44 nucleus"}, 43.955481, 20, 0}},
    {nuc_particle::ca46n, nuc_props{{"ca46n","Ca-46 nucleus"}, 45.953693, 20, 0}},
    {nuc_particle::ca48n, nuc_props{{"ca48n","Ca-48 nucleus"}, 47.952534, 20, 0}},
    // Scandium
    {nuc_particle::sc45n, nuc_props{{"sc45n","Sc-45 nucleus"}, 44.955910, 21, 7/2.}},
    // Titanium
    {nuc_particle::ti46n, nuc_props{{"ti46n","Ti-46 nucleus"}, 45.952629, 22, 0}},
    {nuc_particle::ti47n, nuc_props{{"ti47n","Ti-47 nucleus"}, 46.951764, 22, 5/2.}},
    {nuc_particle::ti48n, nuc_props{{"ti48n","Ti-48 nucleus"}, 47.947947, 22, 0}},
    {nuc_particle::ti49n, nuc_props{{"ti49n","Ti-49 nucleus"}, 48.947871, 22, 7/2.}},
    {nuc_particle::ti50n, nuc_props{{"ti50n","Ti-50 nucleus"}, 49.944792, 22, 0}},
    // Vanadium
    {nuc_particle::v50n, nuc_props{{"v50n","V-50 nucleus"}, 49.947163, 23, 6}},
    {nuc_particle::v51n, nuc_props{{"v51n","V-51 nucleus"}, 50.943964, 23, 7/2.}},
    // Chromium
    {nuc_particle::cr50n, nuc_props{{"cr50n","Cr-50 nucleus"}, 49.946050, 24, 0}},
    {nuc_particle::cr52n, nuc_props{{"cr52n","Cr-52 nucleus"}, 51.940512, 24, 0}},
    {nuc_particle::cr53n, nuc_props{{"cr53n","Cr-53 nucleus"}, 52.940654, 24, 3/2.}},
    {nuc_particle::cr54n, nuc_props{{"cr54n","Cr-54 nucleus"}, 53.938885, 24, 0}},
    // Manganese
    {nuc_particle::mn55n, nuc_props{{"mn55n","Mn-55 nucleus"}, 54.938050, 25, 5/2.}},
    // Iron
    {nuc_particle::fe54n, nuc_props{{"fe54n","Fe-54 nucleus"}, 53.939615, 26, 0}},
    {nuc_particle::fe56n, nuc_props{{"fe56n","Fe-56 nucleus"}, 55.934942, 26, 0}},
    {nuc_particle::fe57n, nuc_props{{"fe57n","Fe-57 nucleus"}, 56.935399, 26, 1/2.}},
    {nuc_particle::fe58n, nuc_props{{"fe58n","Fe-58 nucleus"}, 57.933280, 26, 0}},
};

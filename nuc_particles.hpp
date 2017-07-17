// Nuclei particle map

// Include guard
#ifndef __NUC_PARTICLES_HPP_INCLUDED__
#define __NUC_PARTICLES_HPP_INCLUDED__

#include <cmath>
#include <map>
#include <sstream>
#include "properties.hpp"

class nuc_props : public base_props
{
    using base_props::base_props;
    public:
        virtual const double get_mass_in_kilograms() const override;
        virtual const double get_charge_in_coulombs() const override;
        virtual const double get_spin_quantum_number() const override;
};


enum class nuc_particle
{
    /* Numbers given with five digits. Ex: 1020
     * Patterns:
     *   Digits 2 & 3 give atomic number Z
     *   Digits 4 & 5 give number of nucleons N
     */

    null = 0,

    h1n     = 101,
    h2n     = 102,
    h3n     = 103,
    he3n    = 203,
    he4n    = 204,
    li6n    = 306,
    li7n    = 307,
    be9n    = 409,
    b10n    = 510,
    b11n    = 511,
    c12n    = 612,
    c13n    = 613,
    c14n    = 614,
    n14n    = 714,
    n15n    = 715,
    o16n    = 816,
    o17n    = 817,
    o18n    = 818,
    f19n    = 919,
    ne20n   = 1020,
    ne21n   = 1021,
    ne22n   = 1022,
    na23n   = 1123,
    mg24n   = 1224,
    mg25n   = 1225,
    mg26n   = 1226,
    al27n   = 1327,
    si28n   = 1428,
    si29n   = 1429,
    si30n   = 1430,
    p31n    = 1531,
    s32n    = 1632,
    s33n    = 1633,
    s34n    = 1634,
    s36n    = 1636,
    cl35n   = 1735,
    cl37n   = 1737,
    ar36n   = 1836,
    ar38n   = 1838,
    ar40n   = 1840,
    k39n    = 1939,
    k40n    = 1940,
    k41n    = 1941,
    ca40n   = 2040,
    ca42n   = 2042,
    ca43n   = 2043,
    ca44n   = 2044,
    ca46n   = 2046,
    ca48n   = 2048,
    sc45n   = 2145,
    ti46n   = 2246,
    ti47n   = 2247,
    ti48n   = 2248,
    ti49n   = 2249,
    ti50n   = 2250,
    v50n    = 2350,
    v51n    = 2351,
    cr50n   = 2450,
    cr52n   = 2452,
    cr53n   = 2453,
    cr54n   = 2454,
    mn55n   = 2555,
    fe54n   = 2654,
    fe56n   = 2656,
    fe57n   = 2657,
    fe58n   = 2658,
};

extern std::map<nuc_particle, nuc_props> nuc_properties;

#endif

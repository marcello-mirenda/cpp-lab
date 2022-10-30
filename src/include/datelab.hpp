#include <boost/date_time/gregorian/gregorian.hpp>

namespace datelab
{
    using namespace boost::gregorian;

    struct daysres_s
    {
        daysres_s() {}
        date start;
        date today;
        days _days;
    };

    typedef daysres_s daysres;

    daysres& getDays(daysres& res);
}

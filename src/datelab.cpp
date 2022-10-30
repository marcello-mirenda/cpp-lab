#include <boost/date_time/gregorian/gregorian.hpp>

#include "datelab.hpp"

namespace datelab
{
    using namespace boost::gregorian;

    daysres& getDays(daysres& res)
    {
        auto start = from_simple_string("2022-Apr-25");
        auto today = day_clock::local_day();
        res.start = start;
        res.today = today;
        res._days = today - start;
        return res;
    }
}

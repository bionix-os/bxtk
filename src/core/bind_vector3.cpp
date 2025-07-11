#include "lua_bind.h"

void bxtk::core::bind_vector3(sol::state& lua) {
    lua.new_usertype<godot::Vector3>(
        "Vector3",
        sol::constructors<Vector3(), Vector3(float, float, float)>(),
        "x", &Vector3::x,
        "y", &Vector3::y,
        "z", &Vector3::z,
        "abs", &Vector3::abs,
        "angleTo", &Vector3::angle_to,
        //"bezierDerivative", &Vector3::bezier_derivative,
        "bezierInterpolate", &Vector3::bezier_interpolate,
        "bounce", &Vector3::bounce,
        "ceil", &Vector3::ceil,
        "clamp", &Vector3::clamp,
        //"clampf", &Vector3::clampf,
        "cross", &Vector3::cross,
        "cubicInterpolate", &Vector3::cubic_interpolate,
        "cubicInterpolateInTime", &Vector3::cubic_interpolate_in_time,
        "directionTo", &Vector3::direction_to,
        "distanceSquaredTo", &Vector3::distance_squared_to,
        "distanceTo", &Vector3::distance_to,
        "dot", &Vector3::dot,
        "floor", &Vector3::floor,
        "inverse", &Vector3::inverse,
        "isEqualApprox", &Vector3::is_equal_approx,
        //"isFinite", &Vector3::is_finite,
        "isNormalized", &Vector3::is_normalized,
        "isZeroApprox", &Vector3::is_zero_approx,
        "length", &Vector3::length,
        "lengthSquared", &Vector3::length_squared,
        "limitLength", &Vector3::limit_length,
        "lerp", &Vector3::lerp,
        "max", &Vector3::max,
        "maxAxisIndex", &Vector3::max_axis_index,
        "min", &Vector3::min,
        "minAxisIndex", &Vector3::min_axis_index,
        "moveToward", &Vector3::move_toward,
        "normalize", &Vector3::normalize,
        "normalized", &Vector3::normalized,
        "octahedronDecode", &Vector3::octahedron_decode,
        "octrahedronEncode", &Vector3::octahedron_encode,
        "outer", &Vector3::outer,
        "posmod", &Vector3::posmod,
        "posmodv", &Vector3::posmodv,
        "project", &Vector3::project,
        "reflect", &Vector3::reflect,
        "rotated", &Vector3::rotated,
        "round", &Vector3::round,
        "sign", &Vector3::sign,
        "signedAngleTo", &Vector3::signed_angle_to,
        "slerp", &Vector3::slerp,
        "slide", &Vector3::slide,
        "snapped", &Vector3::snapped,
        "tostring", [](const Vector3& v) { return std::string((v.operator String()).utf8().get_data()); }
    );
}
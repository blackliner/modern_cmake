#include <catch2/catch.hpp>

#include <aero/aero.h>

#include <chrono>

using namespace Catch::literals;
using namespace std::chrono_literals;

SCENARIO("basic kinematics")
{
    GIVEN("a 5kg mass in its default state")
    {
        aero::KinematicObject some_mass;
        some_mass.setMass(5.0);
        some_mass.SetInertia(5.0);

        THEN("position is zero")
        {
            REQUIRE(some_mass.position().norm() == 0.0_a);
        }
        THEN("velocity is zero")
        {
            REQUIRE(some_mass.velocity().norm() == 0.0_a);
        }
        THEN("force is zero")
        {
            REQUIRE(some_mass.force().norm() == 0.0_a);
        }
        THEN("alpha is zero")
        {
            REQUIRE(some_mass.alpha() == 0.0_a);
        }
        THEN("speed is zero")
        {
            REQUIRE(some_mass.speed() == 0.0_a);
        }

        WHEN("the velocity is set to 1m/s for 1s")
        {
            some_mass.setVelocity({1.0, 0.0});

            THEN("velocity is one")
            {
                REQUIRE(some_mass.velocity().norm() == 1.0_a);
            }

            WHEN("the step function is called for 1s")
            {
                some_mass.step(1s);
                THEN("the new position is 1m further")
                {
                    REQUIRE(some_mass.position().norm() == 1.0_a);
                }
            }
        }
        WHEN("a force of 1N is applied")
        {
            some_mass.applyForce({1.0, 0.0});

            THEN("a force of 1N is acting on the mass")
            {
                REQUIRE(some_mass.force().norm() == 1.0_a);
            }

            WHEN("the step function is called for 1s")
            {
                some_mass.step(1s);

                THEN("the velocity is 0.2m/s")
                {
                    REQUIRE(some_mass.velocity().norm() == 0.2_a);
                }
                THEN("the accumulated force is zeroed")
                {
                    REQUIRE(some_mass.force().norm() == 0.0_a);
                }
                THEN("the new position is 0.3m further")
                {
                    REQUIRE(some_mass.position().norm() == 0.3_a);
                }
            }
        }
        WHEN("acceleration is set to 5m/s²")
        {
            some_mass.setAcceleration({5.0, 0.0});
            WHEN("the step function is called for 1s")
            {
                some_mass.step(1s);

                THEN("the velocity is 5.0m/s")
                {
                    REQUIRE(some_mass.velocity().norm() == 5.0_a);
                }
                THEN("the new position is 7.5m further")
                {
                    REQUIRE(some_mass.position().norm() == 7.5_a);
                }
            }
        }
        WHEN("a torque of 1Nm is applied")
        {
            some_mass.applyTorque(1.0);

            THEN("a torque of 1Nm is acting on the mass")
            {
                REQUIRE(some_mass.torque() == 1.0_a);
            }

            WHEN("the step function is called for 1s")
            {
                some_mass.step(1s);

                THEN("the rotational speed is 0.2rad/s")
                {
                    REQUIRE(some_mass.speed() == 0.2_a);
                }
                THEN("alpha is 0.3rad")
                {
                    REQUIRE(some_mass.alpha() == 0.3_a);
                }
                THEN("torque is zeroed")
                {
                    REQUIRE(some_mass.torque() == 0.0_a);
                }
            }
        }
    }
}
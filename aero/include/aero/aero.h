#ifndef AERO_AERO_H
#define AERO_AERO_H

#include <chrono>
#include <Eigen/Core>

namespace aero
{

    class KinematicObject
    {
    public:
        void setMass(double new_mass);
        void SetInertia(double new_inertia);
        void setVelocity(const Eigen::Vector2d &speed);
        void applyForce(const Eigen::Vector2d &force);
        void applyTorque(double torque);
        void setAcceleration(const Eigen::Vector2d &new_acceleration);
        Eigen::Vector2d position() const;
        Eigen::Vector2d velocity() const;
        double speed() const;
        Eigen::Vector2d force() const;
        double alpha() const;
        double torque() const;
        void step(const std::chrono::milliseconds &delta_time);

    private:
        double mass_{};
        double inertia_{};
        double torque_{};
        double alpha_{};
        double speed_{};
        Eigen::Vector2d position_{Eigen::Vector2d::Zero()};
        Eigen::Vector2d velocity_{Eigen::Vector2d::Zero()};
        Eigen::Vector2d force_{Eigen::Vector2d::Zero()};
        Eigen::Vector2d acceleration_{Eigen::Vector2d::Zero()};
    };

} // namespace aero

#endif // AERO_AERO_H

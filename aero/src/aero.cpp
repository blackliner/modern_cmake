#include "aero/aero.h"

namespace aero
{
    void KinematicObject::setMass(double new_mass) { mass_ = new_mass; }
    void KinematicObject::SetInertia(double new_inertia) { inertia_ = new_inertia; }
    void KinematicObject::setVelocity(const Eigen::Vector2d &new_velocity) { velocity_ = new_velocity; }
    void KinematicObject::applyForce(const Eigen::Vector2d &force) { force_ += force; }
    void KinematicObject::applyTorque(double torque) { torque_ += torque; }
    void KinematicObject::setAcceleration(const Eigen::Vector2d &new_acceleration) { acceleration_ = new_acceleration; }
    Eigen::Vector2d KinematicObject::position() const { return position_; }
    Eigen::Vector2d KinematicObject::velocity() const { return velocity_; }
    Eigen::Vector2d KinematicObject::force() const { return force_; }
    double KinematicObject::alpha() const { return alpha_; }
    double KinematicObject::speed() const { return speed_; }
    double KinematicObject::torque() const { return torque_; }
    void KinematicObject::step(const std::chrono::milliseconds &delta_time)
    {
        const auto delta_time_s = std::chrono::duration_cast<std::chrono::duration<double>>(delta_time).count();
        
        const auto acceleration = acceleration_ + force_ / mass_;
        velocity_ += acceleration * delta_time_s;
        position_ += velocity_ * delta_time_s + 0.5 * acceleration * delta_time_s * delta_time_s;

        force_ = Eigen::Vector2d::Zero();

        const auto rot_acceleration = torque_ / inertia_;
        speed_ += rot_acceleration * delta_time_s;
        alpha_ += speed_ * delta_time_s + 0.5 * rot_acceleration * delta_time_s * delta_time_s;

        torque_ = 0.0;
    }

} // namespace aero

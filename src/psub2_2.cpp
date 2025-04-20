//2101069 이시예
//**************************************************
#include "psub2/pub2_2.hpp"
#include "geometry_msgs/msg/vector3.hpp"

Pub::Pub() : Node("mypub")
{
    data_ = geometry_msgs::msg::Vector3();

    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    pub_ = this->create_publisher<geometry_msgs::msg::Vector3>("mytopic", qos_profile);
    timer_ = this->create_wall_timer(1s, std::bind(&Pub::publish_msg, this));
}

void Pub::publish_msg()
{
    data_.x += 1.0;
    data_.y += 1.0;
    data_.z += 1.0;

    RCLCPP_INFO(this->get_logger(), "Publishing: x=%.2f, y=%.2f, z=%.2f", data_.x, data_.y, data_.z);
    pub_->publish(data_);
}
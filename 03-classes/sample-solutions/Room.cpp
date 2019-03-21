#include "Room.h"

Room::Room() : m_room_number(0), m_width(0), m_depth(0), m_height(0), m_price(0) {}

Room::Room(int room_number, double width, double depth, double height, double price) :m_room_number(room_number), m_width(width), m_depth(depth), m_height(height), m_price(price) {}



int Room::room_number() const {
   return m_room_number;
}

double Room::width() const {
   return m_width;
}

double Room::height() const {
   return m_height;
}

double Room::depth() const {
   return m_depth;
}

double Room::price() const {
   return m_price;
}

double Room::volume() const {
   return m_depth * m_width * m_height;
}

void Room::set_room_number(int room_number) {
   m_room_number = room_number;
}

void Room::set_depth(double depth) {
   m_depth = depth;
}

void Room::set_width(double width) {
   m_width = width;
}

void Room::set_height(double height) {
    m_height = height;
}

void Room::set_price(double price) {
   m_price = price;
}

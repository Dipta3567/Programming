//  MODULE - 33 

//  TOPIC - API , JSON DATA , DATA LOAD , DYNAMIC WEBSITES.


// ### What is the Internet?
// The Internet is a global network of interconnected computers and servers that communicate with each other using standardized communication protocols. It allows users to access and share information, resources, and services from anywhere in the world.

// ### How Does the Internet Work?
// 1. **Data Transmission**: Information on the internet is transmitted using packets, which are small units of data. These packets travel across networks to reach their destination.
// 2. **Routers and Switches**: These devices direct the packets across different networks towards their destination.
// 3. **Protocols**: Communication protocols like TCP/IP (Transmission Control Protocol/Internet Protocol) ensure that data is transmitted reliably and correctly.
// 4. **Servers and Clients**: Servers host websites and services, while clients (like your computer or phone) access them.

// ### HTTP vs. HTTPS
// - **HTTP (HyperText Transfer Protocol)**: This is the protocol used for transferring web pages on the internet. It's not secure, meaning data can be intercepted and read.
// - **HTTPS (HyperText Transfer Protocol Secure)**: This is the secure version of HTTP. It uses SSL/TLS encryption to ensure that data transferred between your browser and the server is secure and private.

// ### DNS (Domain Name System)
// DNS translates human-readable domain names (like www.example.com) into IP addresses (like 192.0.2.1) that computers use to identify each other on the network. It's like a phonebook for the internet.

// ### IP (Internet Protocol)
// IP addresses are unique numerical labels assigned to each device connected to a network. They serve two main functions:
// 1. **Identification**: They identify the host or network interface.
// 2. **Location Addressing**: They provide the location of the host in the network.

// ### What is an API?
// API (Application Programming Interface) is a set of rules and protocols for building and interacting with software applications. APIs allow different software systems to communicate with each other, enabling them to exchange data and perform tasks.

// In summary:
// - **Internet**: A global network of connected devices.
// - **HTTP vs. HTTPS**: HTTP is unsecure, HTTPS is secure.
// - **DNS**: Translates domain names to IP addresses.
// - **IP**: Unique addresses for devices on a network.
// - **API**: Allows different software systems to communicate.




//  JSON : STRINGIFY , PARSE

const data = {
    mobile : " apple",
    pp : [1000, 1200 ,1400]
}

console.log(data);

//strigify => string e convert kore sb property 
const strigified = JSON.stringify(data);

console.log(strigified);

// afer form e niye jai
const original = JSON.parse(strigified);

console.log(original);
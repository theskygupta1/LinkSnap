# URL Shortener Service (Stage 4 – In Progress)

A scalable URL shortening service designed with production-grade system design principles.
This project is being developed incrementally to mirror real-world backend engineering workflows.

---

## ✅ Implemented Features (Up to Stage 4)

### Core Functionality
- URL shortening using collision-free ID generation
- Base62 encoding for compact, URL-safe short links
- Redirect handling for short URLs

### Data Modeling
- URL entity modeled with metadata
  - Original URL
  - Creation timestamp
  - Expiry timestamp
- Expired links are invalidated during redirect

### Backend Design
- Clean service-layer abstraction for URL operations
- In-memory storage for fast prototyping
- HTTP backend integration (work in progress)

### Frontend
- Browser-based UI for URL shortening
- User-friendly input and output
- Designed to integrate with REST APIs

---

## 🧠 System Design Concepts Covered

- Base62 encoding vs hashing
- Collision avoidance strategies
- URL lifecycle management (expiry)
- Read-heavy optimization (cache-ready design)
- Rate limiting concepts (design completed, integration pending)
- Scalability considerations (horizontal scaling, sharding-ready)

---

## 🛠 Tech Stack

- **Backend:** C++ (Modern C++)
- **Frontend:** HTML, CSS, JavaScript
- **Version Control:** Git, GitHub
- **Architecture:** REST-based service design
- **Tooling:** VS Code

---

## 🚧 Current Status

- Core backend logic complete
- Expiry handling implemented
- Frontend UI complete
- HTTP server integration in progress
- Designed for Redis cache & database integration

> Note: Full HTTP backend requires a 64-bit toolchain due to modern C++ networking library constraints.

---

## 🔜 Planned Enhancements

- LRU caching for hot URLs
- Rate limiting per client/IP
- Persistent storage (PostgreSQL / file-based)
- Redis-based cache
- Deployment & monitoring
- Load balancer & CDN discussion

---

## 🧾 Resume Summary

Designed and implemented a URL shortening service using Base62 encoding, expiry-based redirects, and scalable backend design principles, with a browser-based frontend and cache-ready architecture.

---

## 📌 Development Approach

This project is intentionally developed in stages to reflect real-world backend engineering practices:
correctness first, followed by performance, safety, and scalability.

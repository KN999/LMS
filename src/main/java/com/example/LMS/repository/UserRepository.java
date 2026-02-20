package com.example.LMS.repository;

import com.example.LMS.entity.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;
import java.util.concurrent.atomic.AtomicInteger;

@Repository
public interface UserRepository extends JpaRepository<User, Integer> {

    public User save(User user);
    public Optional<User> findByEmail(String email);
//    private Map<String, User> database = new HashMap<>();
//    private AtomicInteger idCounter = new AtomicInteger(1);
//
//    public User save(User user) {
//        user.setId(idCounter.getAndIncrement());
//        database.put(user.getEmail(), user);
//        return user;
//    }
//
//    public Optional<User> findByEmail(String email) {
//        return Optional.ofNullable(database.get(email));
//    }
}

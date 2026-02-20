package com.example.LMS.services;

import com.example.LMS.dtos.UserResponse;
import com.example.LMS.dtos.UserSigninRequest;
import com.example.LMS.dtos.UserSignupRequest;
import com.example.LMS.entity.User;
import com.example.LMS.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Service
public class AuthService {

    @Autowired
    private UserRepository userRepository;

    public UserResponse singup(UserSignupRequest request) {
        User user = new User();
        user.setEmail(request.getEmail());
        user.setPassword(request.getPassword());
        user.setPhoneNumber(request.getPhoneNumber());
        user.setName(request.getName());

        User savedUser = userRepository.save(user);

        return new UserResponse(savedUser.getName(), savedUser.getEmail(), savedUser.getPhoneNumber());
    }

    public String singin(UserSigninRequest request) {
        Optional<User> users = userRepository.findByEmail(request.getEmail());
        return users.filter(u -> u.getPassword().equals(request.getPassword()))
                .map(u -> "Login Successful for user: " + u.getName())
                .orElse("Invalid user or email");
    }
}

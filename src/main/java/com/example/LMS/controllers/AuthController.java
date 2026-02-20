package com.example.LMS.controllers;

import com.example.LMS.dtos.UserResponse;
import com.example.LMS.dtos.UserSigninRequest;
import com.example.LMS.dtos.UserSignupRequest;
import com.example.LMS.services.AuthService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/auth")
public class AuthController {

    @Autowired
    private AuthService authService;

    @PostMapping("/signup")
    public ResponseEntity<UserResponse> signup(@RequestBody UserSignupRequest request) {
        return ResponseEntity.ok(authService.singup(request));
    }

    @PostMapping("/signin")
    public ResponseEntity<String> singin(@RequestBody UserSigninRequest request) {
        return ResponseEntity.ok(authService.singin(request));
    }

}

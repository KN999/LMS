package com.example.LMS;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.jdbc.autoconfigure.DataSourceAutoConfiguration;

@SpringBootApplication
public class LmsApplication {

	public static void main(String[] args) {
		System.out.println("Hello World!");
		SpringApplication.run(LmsApplication.class, args);
	}

}

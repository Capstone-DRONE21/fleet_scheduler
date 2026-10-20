# Fleet Scheduler

## Table of Contents
* [Purpose](#purpose)
* [Requirements](#requirements)
* [Design](#design)

# Purpose

## Context

## Problem

## Solution

# Requirements

## Functional

### FR-006
The fleet scheduler SHALL receive event-driven drone state change notifications.

## Non-Functional

### NFR-001	
The fleet scheduler SHALL manage charging requests from multiple drones sharing a single charging pad.

### NFR-002	
The fleet scheduler SHALL consider the battery State of Charge (SoC) when allocating charging windows.

### NFR-003	
The fleet scheduler SHALL consider the battery State of Health (SoH) when allocating charging windows.

### NFR-004
The fleet scheduler SHALL consider each drone’s estimated energy consumption rate when allocating charging windows.

### NFR-005
The fleet scheduler SHALL consider each drone’s estimated time to return when allocating charging windows.

### NFR-006
The fleet scheduler SHALL consider each drone’s estimated latest possible time to begin return when allocating charging windows.

### NFR-007	
The fleet scheduler SHALL consider the current state of each drone and the charging pad when allocating charging windows.

# Design
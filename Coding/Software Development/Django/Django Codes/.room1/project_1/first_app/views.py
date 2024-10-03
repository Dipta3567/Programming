from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.

def courses(request):
    return HttpResponse('This is the courses page')

def about(request):
    return HttpResponse('This is the about page')

def home(request):
    return HttpResponse('This is the home page')
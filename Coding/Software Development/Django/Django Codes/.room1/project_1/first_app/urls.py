from django.urls import path
from . import views

urlpatterns = [
    
    path('courses/', views.courses), #It will not work until you add the path to the urls.py file in the project folder
    path('about/', views.about),
    path('',views.home),
]

from django.urls import path,include
from . import views
urlpatterns = [
    path('',views.home, name='homepage'),
    path('form/',views.form, name='submit_form'),
    path('about/',views.about, name='aboutpage'),
    #path('django_form/',views.DjangoForm, name='django_form'),
    #path('django_form/',views.StudentForm, name='django_form'),
    path('django_form/',views.password_validator, name='django_form'),
]
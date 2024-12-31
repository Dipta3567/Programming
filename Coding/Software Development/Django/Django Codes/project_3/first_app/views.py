from django.shortcuts import render
import datetime
# Create your views here.
def home(request):
    dictonary= {'author' : 'Sai',
                'date' : '27th July 2021',
                'lst' : ['python','is','best'], 
                'age' : 15, 
                'course' : [{'id': 1,'name' : 'Python', 'duration' : '2 months'},
                            {'id': 2,'name' : 'Java', 'duration' : '3 months'},
                            {'id': 3,'name' : 'C++', 'duration' : '1 month'}],
                'birth' : datetime.datetime.now(), 
                'val' : ''
                
                }
    # return render(request, 'first_app/home.html', context=dictonary) this is 1 method
    return render(request, 'first_app/home.html', dictonary) # this is 2nd method  
    # return render(request, 'home.html', dictonary) # if i dont add first_app name in template name

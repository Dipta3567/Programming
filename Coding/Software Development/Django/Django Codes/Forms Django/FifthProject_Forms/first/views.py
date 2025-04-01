from django.shortcuts import render
from . forms import contactForm, StudentData, password_validator_project
# Create your views here.
def home(request):
    if request.method == 'POST':
        name=request.POST.get('username')
        email=request.POST.get('email')
        return render(request,'index.html', {'name':name, 'email':email})
    else:
        return render(request,'index.html')

def form(request):
    #if request.method == 'POST':
    #    name=request.POST.get('username')
    #    email=request.POST.get('email')
    #    return render(request,'form.html', {'name':name, 'email':email})
    #else:
        return render(request,'form.html')
    
    
def about(request):
    if request.method == 'POST':
        print(request.POST)
        name=request.POST.get('username')
        email=request.POST.get('email')
        select = request.POST.get('select')
        return render(request,'about.html', {'name':name, 'email':email, 'select':select})
    else:
        return render(request,'about.html')   
    
    
def DjangoForm (request):
    #Best practice for form
    if request.method == 'POST':
        form = contactForm(request.POST, request.FILES) # request.FILES use korsi jate file upload korte paro
        if form.is_valid():
            file = form.cleaned_data['file']
            # upload kora file upload folder e save korbe
            with open('./first/upload/' + file.name, 'wb+') as destination:
                for chunk in file.chunks(): # file size boro hole chunk use kora hoy jate choto hishabe upload korte pare
                    destination.write(chunk)
            print(form.cleaned_data)
            
    else:
        form = contactForm() #  blank form show korbe
    return render(request,'django_form.html', {'form': form})
    
    
    
    
    #Used for normal lerning
    
    # form = contactForm(request.POST) # request post use korsi jate data enter hole catch kore then form.cleaned_data kaj korbe
    # if form.is_valid(): # form valid hole data clean data te pass hobe
    #     print(form.cleaned_data)
    # return render(request,'django_form.html', {'form': form})
    
    
def StudentForm(request):
    if request.method == 'POST':
        form = StudentData(request.POST, request.FILES)
        if form.is_valid():
            print(form.cleaned_data)
    else:
        form = StudentData()
    return render(request,'django_form.html', {'form': form})


def password_validator(request):
    if request.method == 'POST':
        form = password_validator_project(request.POST, request.FILES)
        if form.is_valid():
            print(form.cleaned_data)
    else:
        form = password_validator_project()
    return render(request,'django_form.html', {'form': form})



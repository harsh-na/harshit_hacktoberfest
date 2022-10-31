import os
import shutil

def create_folder_if_not (folder):
    if not os.path.exists(folder):
        os.makedirs(folder)

files = os.listdir()

create_folder_if_not('Images')
create_folder_if_not('Media')
create_folder_if_not('Docs')
create_folder_if_not('Programming')
create_folder_if_not('Application')

img_ext = ['.jpg', '.jpeg', '.png']
media_ext = ['.mp4', '.mp3', '.mkv']
docs_ext = ['.doc', '.docx', '.pdf', '.pptx']
prog_ext = ['.py', '.cs', '.sln', '.csproj', '.js', '.css', '.htm', '.html']
exe_ext = ['.exe']
images = [file for file in files if os.path.splitext(file)[1].lower() in img_ext]
media = [file for file in files if os.path.splitext(file)[1].lower() in media_ext]
docs = [file for file in files if os.path.splitext(file)[1].lower() in docs_ext]
prog = [file for file in files if os.path.splitext(file)[1].lower() in prog_ext]
application = [file for file in files if os.path.splitext(file)[1].lower() in exe_ext]

for i in prog:
    if os.path.splitext(i)[0].lower() == 'arrange_files':
        prog.remove('arrange_files.py')


for i in images:
    shutil.move(f'{i}', f'Images/{i}')
for i in media:
    shutil.move(f'{i}', f'Media/{i}')
for i in docs:
    shutil.move(f'{i}', f'Docs/{i}')
for i in prog:
    shutil.move(f'{i}', f'Programming/{i}')
for i in application:
    shutil.move(f'{i}', f'Application/{i}')


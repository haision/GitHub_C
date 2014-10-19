Name:		nginx
Version:	1.5.1
Release:	4
Summary:	this is a test rpm.

Group:		Development/Tools
License:	GPL
URL:		http://www.thyhakcer.com
Source0:	%{name}-%{version}.tar.gz
%define nginx_datadir /usr/local/nginx

BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

Requires:	libpng-devel >= 1.0.20 zlib

%description	
this is my firt rpm maked by myself!


%prep
%setup -q

%postun
rm -rf %{nginx_datadir}
echo hello,thy,this rpm removed finished!

%build
mkdir -p %{nginx_datadir}/
mkdir -p %{nginx_datadir}/logs/ 
mkdir -p %{nginx_datadir}/tmp/{client,proxy,fcgi}
mkdir -p %{nginx_datadir}/pid
mkdir -p %{nginx_datadir}/lock
./configure \
--prefix=%{nginx_datadir} \
--sbin-path=%{nginx_datadir}/sbin/nginx \
--conf-path=%{nginx_datadir}/conf/nginx.conf \
--error-log-path=%{nginx_datadir}/logs/error.log \
--pid-path=%{nginx_datadir}/pid/nginx.pid \
--lock-path=%{nginx_datadir}/lock/nginx.lock \
--http-log-path=%{nginx_datadir}/logs/access.log \
--http-client-body-temp-path=%{nginx_datadir}/tmp/client \
--http-proxy-temp-path=%{nginx_datadir}/tmp/proxy \
--http-fastcgi-temp-path=%{nginx_datadir}/tmp/fcgi \
--user=nginx \
--group=nginx \
--with-http_ssl_module \
--with-http_flv_module \
--with-http_gzip_static_module \
--with-http_stub_status_module 

make

%install
rm -rf %{buildroot}
make install DESTDIR=%{buildroot}


%clean
rm -rf %{buildroot}


%files
%defattr(-,root,root,-)
%doc README
/usr/local/nginx/*

%changelog


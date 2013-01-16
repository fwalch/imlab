create table account_permission (
  ap_ca_id integer not null,
  ap_acl char(4) not null,
  ap_tax_id char(20) not null,
  ap_l_name char(255) not null,
  ap_f_name char(255) not null,
  primary key(ap_ca_id)
);
create table customer (
  c_id integer not null,
  c_tax_id char(20) not null,
  c_st_id char(4) not null,
  c_l_name char(25) not null,
  c_f_name char(20) not null,
  c_m_name char(1),
  c_gndr char(1),
  c_tier integer not null,
  c_dob timestamp not null,
  c_ad_id integer not null,
  c_ctry_1 char(3),
  c_area_1 char(3),
  c_local_1 char(10),
  c_ext_1 char(5),
  c_ctry_2 char(3),
  c_area_2 char(3),
  c_local_2 char(10),
  c_ext_2 char(5),
  c_ctry_3 char(3),
  c_area_3 char(3),
  c_local_3 char(10),
  c_ext_3 char(5),
  c_email_1 char(50),
  c_email_2 char(50),
  primary key (c_id)
);